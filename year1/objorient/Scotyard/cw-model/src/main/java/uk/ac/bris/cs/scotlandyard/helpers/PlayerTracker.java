package uk.ac.bris.cs.scotlandyard.helpers;

import com.google.common.collect.ImmutableList;

import uk.ac.bris.cs.scotlandyard.model.Move;
import uk.ac.bris.cs.scotlandyard.model.Move.DoubleMove;
import uk.ac.bris.cs.scotlandyard.model.Move.FunctionalVisitor;
import uk.ac.bris.cs.scotlandyard.model.Move.SingleMove;
import uk.ac.bris.cs.scotlandyard.model.Player;
import uk.ac.bris.cs.scotlandyard.model.ScotlandYard.Ticket;

/**
 * Helper: A class that manages the state of players in the game
 *
 *  <blockquote><em>&mdash; Taharka O.</em></blockquote>
 */
public final class PlayerTracker {
  /**
   * @param thisPlayer the player to move
   * @param move       the move that moves the player
   * @return the updated player
   * @apiNote the method {@code Move.use(Iterable<Ticket>)} does not seem to
   *          accurately update the player state, so {@code Move.use(Ticket)} is
   *          used twice.
   */
  public static Player getMovedPlayer(final Player thisPlayer, final Move move) {
    return move.visit(new FunctionalVisitor<Player>(/*  */
        (final SingleMove m) -> {
          return thisPlayer.use(m.ticket).at(m.destination);
        }, /*  */
        (final DoubleMove m) -> {
          return thisPlayer.use(m.ticket1).at(m.destination1).use(m.ticket2).at(m.destination2).use(Ticket.DOUBLE);
        }));
  }

  /**
   * @param mrX the player Mr X
   * @param move the last used move
   * @return Mr X with the tickets last used
   */
  public static Player updateMrXTickets(final Player mrX, final Move move) {
    return mrX.give(move.visit(new FunctionalVisitor<ImmutableList<Ticket>>(/*  */
        (final SingleMove m) -> {
          return ImmutableList.of(m.ticket);
        }, /*  */
        (final DoubleMove m) -> {
          return ImmutableList.of(m.ticket1, m.ticket2);
        })));
  }
}