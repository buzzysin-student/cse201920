package uk.ac.bris.cs.scotlandyard.ui.ai.taharka.ai.test;

import java.util.HashMap;

import uk.ac.bris.cs.scotlandyard.model.Move;
import uk.ac.bris.cs.scotlandyard.ui.ai.taharka.lib.Library;

public abstract class Test {

  protected Move getMinMove(HashMap<Move, Double> solutions) {
    var temp = new HashMap<Move, Double>(solutions);

    solutions.entrySet().stream()
        .filter(solution -> solution.getKey().source() == Library.moveDestination(solution.getKey()))
        .forEach(solution -> {
          temp.put(solution.getKey(), solution.getValue());
        });

    var min = temp.entrySet().stream().min((e1, e2) -> e1.getValue().compareTo(e2.getValue()));

    if (min.isEmpty()) {
      min = solutions.entrySet().stream().findAny();
    }

    System.out.println(min.get().getKey().commencedBy() + " chose " + min);
    solutions.clear();

    return min.get().getKey();
  }
}