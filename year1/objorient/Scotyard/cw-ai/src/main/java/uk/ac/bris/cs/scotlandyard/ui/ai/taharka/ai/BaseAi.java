package uk.ac.bris.cs.scotlandyard.ui.ai.taharka.ai;

import java.util.Random;
import java.util.concurrent.atomic.AtomicBoolean;

import com.google.common.collect.ImmutableList;

import uk.ac.bris.cs.scotlandyard.model.Ai;
import uk.ac.bris.cs.scotlandyard.model.Board;
import uk.ac.bris.cs.scotlandyard.model.Move;
import uk.ac.bris.cs.scotlandyard.ui.ai.taharka.lib.Library;

public interface BaseAi extends Ai {
  public static Boolean isMrXAi = false;

  public default Move randomMove(final Board board, final AtomicBoolean terminate) {
    final var moves = ImmutableList.copyOf(board.getAvailableMoves());
    return moves.get(new Random().nextInt(moves.size()));
  }

  public Move intelligentMove(Board board, AtomicBoolean terminate);

  public interface DetectiveAi extends BaseAi {
    public default Move pickMove(final Board board, final AtomicBoolean terminate) {
      if (isMrXAi == false && !Library.mrXsTurn(board))
        return intelligentMove(board, terminate);

      return randomMove(board, terminate);
    }
  }

  public interface MrXAi extends BaseAi {
    public static Boolean isMrXAi = true;

    public default Move pickMove(final Board board, final AtomicBoolean terminate) {
      if (isMrXAi == true && Library.mrXsTurn(board))
        return intelligentMove(board, terminate);

      return randomMove(board, terminate);
    }
  }
}