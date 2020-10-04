package uk.ac.bris.cs.scotlandyard.helpers;

import com.google.common.collect.ImmutableList;

import uk.ac.bris.cs.scotlandyard.model.GameSetup;
import uk.ac.bris.cs.scotlandyard.model.LogEntry;
import uk.ac.bris.cs.scotlandyard.model.Move;
import uk.ac.bris.cs.scotlandyard.model.Move.DoubleMove;
import uk.ac.bris.cs.scotlandyard.model.Move.FunctionalVisitor;
import uk.ac.bris.cs.scotlandyard.model.Move.SingleMove;

/**
 * Helper: A class that manages updates to {@code ImmutableList<LogEntry>}
 * 
 * <blockquote><em>&mdash; Taharka O.</em></blockquote>
 */
public final class LogPusher {
  /**
   * @param log the log to update
   * @param setup the game setup (rounds, graph)
   * @param move the single move used to update the log
   * @return the updated log entry
   */
  public static ImmutableList<LogEntry> pushToLog(final ImmutableList<LogEntry> log, final GameSetup setup,
      final SingleMove move) {
    if (move.commencedBy().isMrX())
      if (setup.rounds.get(log.size()))
        return ImmutableList.<LogEntry>builder()/*  */
            .addAll(log)/*  */
            .add(LogEntry.reveal(move.ticket, move.destination))/*  */
            .build();
      else
        return ImmutableList.<LogEntry>builder()/*  */
            .addAll(log)/*  */
            .add(LogEntry.hidden(move.ticket))/*  */
            .build();
    else
      return log;
  }

  /**
   * @param log the log to update
   * @param setup the game setup (rounds, graph)
   * @param move the double move used to update the log
   * @return the updated log entry
   */
  public static ImmutableList<LogEntry> pushToLog(final ImmutableList<LogEntry> log, final GameSetup setup,
      final DoubleMove move) {
    if (move.commencedBy().isMrX()) {
      final ImmutableList<LogEntry> firstLog = pushToLog(log, setup,
          new SingleMove(move.commencedBy(), move.source(), move.ticket1, move.destination1));
      final ImmutableList<LogEntry> secondLog = pushToLog(firstLog, setup,
          new SingleMove(move.commencedBy(), move.destination1, move.ticket2, move.destination2));
      return secondLog;
    } else
      return log;
  }

  /**
   * @param log the log to update
   * @param setup the game setup (rounds, graph)
   * @param move the move(single or double) used to update the log
   * @return the updated log entry
   */
  public static ImmutableList<LogEntry> logPlayer(final ImmutableList<LogEntry> log, final GameSetup setup,
      final Move move) {
    return move.visit(new FunctionalVisitor<ImmutableList<LogEntry>>((final SingleMove m) -> {
      return LogPusher.pushToLog(log, setup, m);
    }, (final DoubleMove m) -> {
      return LogPusher.pushToLog(log, setup, m);
    }));
  }
}