package uk.ac.bris.cs.scotlandyard.helpers;

import java.util.ArrayList;
import java.util.List;

import com.google.common.collect.ImmutableSet;

import uk.ac.bris.cs.scotlandyard.model.GameSetup;
import uk.ac.bris.cs.scotlandyard.model.Move;
import uk.ac.bris.cs.scotlandyard.model.Move.DoubleMove;
import uk.ac.bris.cs.scotlandyard.model.Move.SingleMove;
import uk.ac.bris.cs.scotlandyard.model.Player;
import uk.ac.bris.cs.scotlandyard.model.ScotlandYard.Ticket;

/**
 * Helper: A factory class that builds moves based on the game state
 * 
 * <blockquote><em>&mdash; Taharka O.</em></blockquote>
 */
public final class MoveFactory {
  /**
   * @param setup      the setup of the game state
   * @param detectives all detectives
   * @param player     the player for who the {@code SingleMove}s should be
   *                   generated for
   * @return {@code SingleMove}s for the player
   */
  private static ImmutableSet<SingleMove> getSingles(final GameSetup setup, final List<Player> detectives,
      final Player player) {
    final ArrayList<SingleMove> singleMoves = new ArrayList<>();
    final int source = player.location();
    setup.graph.adjacentNodes(source).stream().forEach(destination -> {
      if (detectives.stream().anyMatch(d -> d.location() == destination))
        return;
      if (player.isMrX() && player.has(Ticket.SECRET))
        singleMoves.add(new SingleMove(player.piece(), source, Ticket.SECRET, destination));

      setup.graph.edgeValueOrDefault(source, destination, ImmutableSet.of()).forEach(t -> {
        if (player.has(t.requiredTicket()))
          singleMoves.add(new SingleMove(player.piece(), source, t.requiredTicket(), destination));
      });
    });
    return ImmutableSet.copyOf(singleMoves);
  }

  /**
   * @param setup      the setup of the game state
   * @param detectives all detectives
   * @param mrX        the player for who the {@code DoubleMoves}s should be
   *                   generated for (should only be used on Mr X)
   * @return {@code DoubleMoves}s for the player
   * @apiNote This method is an abstraction of sorts, since only Mr X will use
   *          this method
   */
  private static ImmutableSet<Move> getDoubles(final GameSetup setup, final List<Player> detectives, final Player mrX) {

    if (!mrX.has(Ticket.DOUBLE))
      return ImmutableSet.of();
    if (setup.rounds.size() < 2)
      return ImmutableSet.of();

    final ArrayList<DoubleMove> doubleMoves = new ArrayList<>();
    final ArrayList<SingleMove> singleMoves = new ArrayList<>(getSingles(setup, detectives, mrX));

    singleMoves.forEach(m -> {
      setup.graph.adjacentNodes(m.destination).forEach(destination -> {
        if (detectives.stream().anyMatch(d -> d.location() == destination))
          return;
        if (mrX.hasAtLeast(Ticket.SECRET, 2))
          doubleMoves.add(new DoubleMove(mrX.piece(), m.source(), m.ticket, m.destination, Ticket.SECRET, destination));

        setup.graph.edgeValueOrDefault(m.destination, destination, ImmutableSet.of()).forEach(t -> {
          Ticket required = t.requiredTicket();
          final Boolean playerCanMakeDuplicateMove = m.ticket.equals(required) && mrX.hasAtLeast(m.ticket, 2);
          final Boolean playerCanMakeUniqueMoves2x = !m.ticket.equals(required) && mrX.has(required);
          if (playerCanMakeDuplicateMove || playerCanMakeUniqueMoves2x)
            doubleMoves.add(new DoubleMove(mrX.piece(), m.source(), m.ticket, m.destination, required, destination));
        });
      });
    });
    return ImmutableSet.copyOf(doubleMoves);
  }

  /**
   * @param setup      the setup of the game state
   * @param detectives all detectives
   * @param detective  the detective for whom the {@code SingleMove}s are generated
   * @return {@code SingleMove}s for a given detective
   */
  public static ImmutableSet<SingleMove> generateDetectiveMoves(final GameSetup setup, final List<Player> detectives,
      final Player detective) {
    return getSingles(setup, detectives, detective);
  }

  /**
   * @param setup the setup of the game state
   * @param detectives all detectives
   * @return {@code SingleMove}s for all detectives
   */
  public static ImmutableSet<Move> generateAllDetectiveMoves(final GameSetup setup, final List<Player> detectives) {
    final ImmutableSet.Builder<Move> availableMoves = new ImmutableSet.Builder<>();
    detectives.forEach(d -> availableMoves.addAll(generateDetectiveMoves(setup, detectives, d)));
    return availableMoves.build();
  }

  /**
   * @param setup the setup of the game state
   * @param detectives all detectives
   * @param mrX the player Mr X
   * @return all available {@code Move}s for Mr X, Single and Double
   */
  public static ImmutableSet<Move> generateMrXMoves(final GameSetup setup, final List<Player> detectives,
      final Player mrX) {
    return ImmutableSet.<Move>builder()/*  */
        .addAll(getSingles(setup, detectives, mrX))/*  */
        .addAll(getDoubles(setup, detectives, mrX)).build();
  }

  /**
   * @param setup the setup of the game state
   * @param detectives all detectives
   * @param mrX the player Mr X
   * @return {@code Move}s for all players, including MrX
   * @apiNote this was mostly used in testing
   */
  public static ImmutableSet<Move> generateAllAvailableMoves(final GameSetup setup, final List<Player> detectives,
      final Player mrX) {
    ImmutableSet.Builder<Move> availableMoves = new ImmutableSet.Builder<>();
    availableMoves/*  */
        .addAll(generateMrXMoves(setup, detectives, mrX)).addAll(generateAllDetectiveMoves(setup, detectives));
    return availableMoves.build();
  }
}