package uk.ac.bris.cs.scotlandyard.model;

import static uk.ac.bris.cs.scotlandyard.helpers.CommonFilter.findPlayerByPiece;
import static uk.ac.bris.cs.scotlandyard.helpers.LogPusher.logPlayer;
import static uk.ac.bris.cs.scotlandyard.helpers.MoveFactory.generateAllDetectiveMoves;
import static uk.ac.bris.cs.scotlandyard.helpers.MoveFactory.generateMrXMoves;
import static uk.ac.bris.cs.scotlandyard.helpers.MoveFactory.generateAllAvailableMoves;
import static uk.ac.bris.cs.scotlandyard.helpers.MoveFactory.generateDetectiveMoves;
import static uk.ac.bris.cs.scotlandyard.helpers.PlayerTracker.getMovedPlayer;

import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

import javax.annotation.Nonnull;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;

import uk.ac.bris.cs.scotlandyard.helpers.PlayerTracker;
import uk.ac.bris.cs.scotlandyard.helpers.TypeConverter;
import uk.ac.bris.cs.scotlandyard.model.Board.GameState;
import uk.ac.bris.cs.scotlandyard.model.Piece.Detective;
import uk.ac.bris.cs.scotlandyard.model.ScotlandYard.Factory;
import uk.ac.bris.cs.scotlandyard.model.ScotlandYard.Ticket;

/**
 * cw-model Stage 1: Complete this class
 */
public class MyGameStateFactory implements Factory<GameState> {

  private class MyGameState implements GameState {
    private final GameSetup setup;
    private ImmutableList<LogEntry> log;
    private ImmutableList<Player> everyone;
    private ImmutableSet<Piece> remaining;
    private List<Player> detectives;
    private Player mrX;
    private final TypeConverter<Player, Piece> toPiece;

    private MyGameState(final GameSetup setup, final ImmutableSet<Piece> remaining, final ImmutableList<LogEntry> log,
        final Player mrX, final List<Player> detectives) {
      this.setup = setup;
      this.log = log;
      this.mrX = mrX;
      this.remaining = remaining;
      this.detectives = detectives;
      this.everyone = ImmutableList.<Player>builder().add(mrX).addAll(detectives).build();
      this.toPiece = new TypeConverter<Player, Piece>(/*  */
          Player::piece, p -> everyone.stream().filter(findPlayerByPiece(p)).findFirst().get());

      verifyGameStateConstructor(setup, mrX, detectives);
    }

    @Override
    public GameSetup getSetup() {
      return setup;
    }

    @Override
    public ImmutableSet<Piece> getPlayers() {
      return ImmutableSet.copyOf(toPiece.convert(everyone));
    }

    @Override
    public Optional<Integer> getDetectiveLocation(final Detective detective) {
      final Optional<Player> player = detectives.stream().filter(findPlayerByPiece(detective)).findFirst();
      if (player.isPresent())
        return Optional.of(player.get().location());

      return Optional.empty();
    }

    @Override
    public Optional<TicketBoard> getPlayerTickets(final Piece piece) {
      // ? Find our player by the piece they're holding
      final Optional<Player> player = everyone.stream().filter(findPlayerByPiece(piece)).findFirst();
      // ? If the player exists, return their tickets
      if (player.isPresent())
        return Optional.of(new TicketBoard() {
          @Override
          public int getCount(final Ticket ticket) {
            return player.get().tickets().get(ticket);
          }
        });
      // ? Otherwise, return nothing
      return Optional.empty();
    }

    @Override
    public ImmutableList<LogEntry> getMrXTravelLog() {
      return log;
    }

    @Override
    public ImmutableSet<Piece> getWinner() {
      ImmutableSet<Move> allMoves = generateAllAvailableMoves(setup, detectives, mrX);
      ImmutableSet<Move> mrXMoves = allMoves.stream().filter(p -> p.commencedBy().isMrX())
          .collect(ImmutableSet.toImmutableSet());
      ImmutableSet<Move> detMoves = allMoves.stream().filter(p -> p.commencedBy().isDetective())
          .collect(ImmutableSet.toImmutableSet());
      ImmutableSet<Piece> winningDetectives = ImmutableSet.copyOf(toPiece.convert(detectives));
      ImmutableSet<Piece> winningMrX = ImmutableSet.of(toPiece.convert(mrX));

      Boolean roundsOver = log.size() >= setup.rounds.size();
      ImmutableSet<Piece> noOne = ImmutableSet.of();

      // ? Reasons for detectives to win
      if (mrXMoves.isEmpty())
        return winningDetectives;
      else if (detectives.stream().anyMatch(d -> d.location() == mrX.location()))
        return winningDetectives;
      // ? Reasons for Mr X to win
      else if (detMoves.isEmpty())
        return winningMrX;
      else if (roundsOver)
        return winningMrX;

      return noOne;
    }

    @Override
    public ImmutableSet<Move> getAvailableMoves() {
      if (getWinner().isEmpty())
        if (remaining.contains(mrX.piece()))
          return generateMrXMoves(setup, detectives, mrX);
        else
          return generateAllDetectiveMoves(setup, ImmutableList.copyOf(toPiece.revert(remaining)));
      else
        return ImmutableSet.of();
    }

    @Override
    public GameState advance(final Move move) {
      if (!getAvailableMoves().contains(move) && getWinner().isEmpty())
        throw new IllegalArgumentException("The move " + move + " is not allowed in this context: \nDetectives: "
            + detectives + "\nMr. X: " + mrX + "\nAvailable Moves: " + getAvailableMoves() + "\nWin State: " + true);

      // ? Obtain the piece that moved
      final Piece ofInterest = move.commencedBy();

      // ? Update player position
      final Player oldPlayer = everyone.stream().filter(findPlayerByPiece(ofInterest)).findFirst().get();
      final Player newPlayer = getMovedPlayer(oldPlayer, move);

      // ? Update log
      log = logPlayer(log, setup, move);

      // ? Update Mr X
      if (newPlayer.isMrX())
        mrX = newPlayer;

      // ? Assign Mr X new cards
      if (newPlayer.isDetective())
        mrX = PlayerTracker.updateMrXTickets(mrX, move);

      // ? Return the updated state
      final GameState newGameState = prepareForStateChange(newPlayer);
      return newGameState;
    }

    private GameState prepareForStateChange(final Player newPlayer) {
      // ? Replace old player with new one
      everyone = everyone.stream().map(p -> p.piece().equals(newPlayer.piece()) ? newPlayer : p)
          .collect(ImmutableList.toImmutableList());

      // ? New player has played already, so remove it from the queue
      remaining = remaining.stream()/*  */
          .filter(r -> !r.equals(newPlayer.piece()))/*  */
          // ? Also remove players if they have no moves left
          .filter(r -> !generateDetectiveMoves(setup, detectives, toPiece.revert(r)).isEmpty())/*  */
          .collect(ImmutableSet.toImmutableSet());

      // ? If the round is over, add Mr X then detectives back in
      if (remaining.isEmpty())
        remaining = ImmutableSet.<Piece>builder().add(mrX.piece()).addAll(toPiece.convert(detectives)).build();

      // ? Update detectives with new locations
      detectives = everyone.stream().filter(Player::isDetective).collect(Collectors.toList());

      // ? Return the updated state
      return new MyGameState(setup, remaining, log, mrX, detectives);
    }
  }

  @Nonnull
  @Override
  public GameState build(final GameSetup setup, final Player mrX, final ImmutableList<Player> detectives) {
    final ImmutableSet<Piece> remaining = ImmutableSet.<Piece>builder().add(mrX.piece())
        .addAll(detectives.stream().map(Player::piece).collect(ImmutableSet.toImmutableSet())).build();
    final ImmutableList<LogEntry> log = ImmutableList.of();

    return new MyGameState(setup, remaining, log, mrX, detectives);
  }

  /**
   * A cheeky little static method used to verify the constructor state before
   * proceeding
   * 
   * @param setup      the setup given in the constructor
   * @param mrX        the player Mr X
   * @param detectives the detectives to play in the game
   */
  private static void verifyGameStateConstructor(final GameSetup setup, final Player mrX,
      final List<Player> detectives) {
    if (setup.rounds.isEmpty())
      throw new IllegalArgumentException("Game has no rounds!");
    if (setup.graph.nodes().isEmpty())
      throw new IllegalArgumentException("No empty graph allowed!");
    if (mrX.equals(null))
      throw new IllegalArgumentException("There is no Mr. X player!");
    /**
     * ? Not part of the tests, but I thought I should include it => Taharka O.
     */
    if (mrX.isDetective())
      throw new IllegalArgumentException("Mr X is a detective?!");

    detectives.stream().forEach(d -> {
      if (d.has(Ticket.DOUBLE) || d.has(Ticket.SECRET))
        throw new IllegalArgumentException("A detective has illegal cards!");
      if (detectives.stream().filter(fraud -> fraud.equals(d)).count() > 1)
        throw new IllegalArgumentException("Duplicate detective detected!");
      if (detectives.stream().filter(e -> !d.equals(e)).filter(overlap -> overlap.location() == d.location())
          .count() != 0)
        throw new IllegalArgumentException("Two detectives are sharing a location!");
    });
  }

}