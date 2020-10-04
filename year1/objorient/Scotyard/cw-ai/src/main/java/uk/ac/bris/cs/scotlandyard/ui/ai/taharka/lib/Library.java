package uk.ac.bris.cs.scotlandyard.ui.ai.taharka.lib;

import java.io.IOException;

import uk.ac.bris.cs.scotlandyard.model.Board;
import uk.ac.bris.cs.scotlandyard.model.Move;
import uk.ac.bris.cs.scotlandyard.model.Move.FunctionalVisitor;
import uk.ac.bris.cs.scotlandyard.ui.ai.taharka.lib.algorithms.AStar;
import uk.ac.bris.cs.scotlandyard.ui.ai.taharka.lib.algorithms.AStarMrX;
import uk.ac.bris.cs.scotlandyard.ui.ai.taharka.lib.algorithms.Dijkstra;

public final class Library {

  public static boolean mrXsTurn(final Board board) {
    return board.getAvailableMoves().stream().anyMatch(m -> m.commencedBy().isMrX());
  }

  public static Integer moveDestination(final Move move) {
    return move.visit(new FunctionalVisitor<>(m -> m.destination, m -> m.destination2));
  }

  public static void main(final String[] args) throws IOException {
    final Integer start = 2;
    final Integer end = 175;
    final var dSolution = new Dijkstra(ArbitraryTest.scotyard.get(), start, end).getSolution();
    System.out.println(dSolution);
    final var aSolution = new AStar(ArbitraryTest.scotyard.get(), start, end).getSolution();
    System.out.println(aSolution);
    final var bsolver = new AStarMrX(ArbitraryTest.staticboard, start, end);
    bsolver.detectiveLocations().forEach(d -> System.out.print(d + " "));
    System.out.println();
    final var bSolution = bsolver.getSolution();
    bSolution.forEach(n -> System.out.print(n + " "));
    System.out.println();
  }

}