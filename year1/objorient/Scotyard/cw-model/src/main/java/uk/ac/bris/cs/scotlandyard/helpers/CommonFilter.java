package uk.ac.bris.cs.scotlandyard.helpers;

import java.util.function.Predicate;

import uk.ac.bris.cs.scotlandyard.model.Piece;
import uk.ac.bris.cs.scotlandyard.model.Player;

/**
 * Helper: Filters commonly used in {@link MyGameStateFactory}
 * 
 * <blockquote><em>&mdash; Taharka O.</em></blockquote>
 */
public final class CommonFilter {
  /**
   * @param piece the piece used by a player to find in {@code Iterable<Player>}
   * @return a filter function
   */
  public static Predicate<? super Player> findPlayerByPiece(final Piece piece) {
    return p -> p.piece().equals(piece);
  }

  /**
   * @param player the player that uses the piece in {@code Iterable<Piece>}
   * @return a filter function
   */
  public static Predicate<? super Piece> findPieceByPlayer(final Player player) {
    return p -> p.equals(player.piece());
  }
}