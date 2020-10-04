package uk.ac.bris.cs.scotlandyard.ui.ai.taharka.ai.test;

import java.util.HashMap;
import java.util.Optional;
import java.util.Random;
import java.util.concurrent.atomic.AtomicBoolean;

import uk.ac.bris.cs.scotlandyard.model.Board;
import uk.ac.bris.cs.scotlandyard.model.Move;
import uk.ac.bris.cs.scotlandyard.ui.ai.taharka.ai.BaseAi.DetectiveAi;
import uk.ac.bris.cs.scotlandyard.ui.ai.taharka.lib.Library;
import uk.ac.bris.cs.scotlandyard.ui.ai.taharka.lib.algorithms.AStar;

public class DetectiveTest extends Test implements DetectiveAi {

  private HashMap<Move, Double> solutions;

  public DetectiveTest() {
    solutions = new HashMap<Move, Double>();
  }

  @Override
  public Move intelligentMove(Board board, AtomicBoolean terminate) {

    var moves = board.getAvailableMoves();
    var mrXProbableLocation = board.getMrXTravelLog().reverse().stream().map(e -> e.location())
        .filter(l -> l.isPresent()).findFirst().orElseGet(() -> Optional.of(new Random().nextInt(198) + 1)).get();

    moves.parallelStream()
        .forEach(m -> {

          var destination = Library.moveDestination(m);
          var solution = new AStar(board.getSetup().graph, destination, mrXProbableLocation);
          System.out.println("MrX is (probably) near " + mrXProbableLocation);
          solution.getSolution();

          solutions.put(m, solution.nodeCostsMap().entrySet().stream().filter(n -> !n.getKey().equals(destination))
              .min((e1, e2) -> e1.getValue().compareTo(e2.getValue())).get().getValue());

          System.out.println(m + " -> " + solutions.get(m));
        });

    return getMinMove(solutions);
  }

  @Override
  public String name() {
    return "Test: Detective";
  }

}