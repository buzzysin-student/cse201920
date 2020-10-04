package uk.ac.bris.cs.scotlandyard.ui.ai.taharka.ai.test;

import java.util.HashMap;
import java.util.Random;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.function.Function;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;

import uk.ac.bris.cs.scotlandyard.model.Board;
import uk.ac.bris.cs.scotlandyard.model.Move;
import uk.ac.bris.cs.scotlandyard.model.Move.FunctionalVisitor;
import uk.ac.bris.cs.scotlandyard.model.Piece;
import uk.ac.bris.cs.scotlandyard.model.Piece.Detective;
import uk.ac.bris.cs.scotlandyard.model.ScotlandYard.Ticket;
import uk.ac.bris.cs.scotlandyard.model.ScotlandYard.Transport;
import uk.ac.bris.cs.scotlandyard.ui.ai.taharka.ai.BaseAi.MrXAi;
import uk.ac.bris.cs.scotlandyard.ui.ai.taharka.lib.Library;
import uk.ac.bris.cs.scotlandyard.ui.ai.taharka.lib.algorithms.AStarMrX;
import uk.ac.bris.cs.scotlandyard.ui.ai.taharka.lib.traits.CalculatesNodalDistance;

public class MrXTest extends Test implements MrXAi, CalculatesNodalDistance<Integer, ImmutableSet<Transport>> {

  public MrXTest() {
    super();
  }

  @Override
  public Move intelligentMove(Board board, AtomicBoolean terminate) {

    var moves = board.getAvailableMoves();
    var solutions = new HashMap<Move, Double>();
    ImmutableList<Piece> detectives = board.getPlayers().stream().filter(Piece::isDetective)
        .collect(ImmutableList.toImmutableList());

    int nearestPlayer = 5;
    int temp;
    for (int i = 0; i < detectives.size(); i++) {
      Integer end = board.getDetectiveLocation((Detective) detectives.get(i)).get();
      temp = nodalDistance(board.getSetup().graph, moves.asList().get(0).source(), end);
      if (temp < nearestPlayer)
        nearestPlayer = temp;
    }
    var roundNum = board.getMrXTravelLog().size();

    Function<Move, Ticket> ticket = move -> move.visit(new FunctionalVisitor<Ticket>(m -> m.ticket, m -> m.ticket2));

    var normalMoves = moves.stream().filter(m -> m.visit(new FunctionalVisitor<Boolean>(sm -> true, dm -> false)))
        .filter(m -> !ticket.apply(m).equals(Ticket.SECRET)).collect(ImmutableList.toImmutableList());

    var mrXMoves = moves.stream().filter(m -> !normalMoves.contains(m)).collect(ImmutableList.toImmutableList());

    var samplingMoveBuilder = ImmutableList.<Move>builder();

    // samples a given number of moves from a normal single move list and a list of mrX's moves
    int samples = 20;
    int mrXSamples = 10;
    for (int i = 0; i < samples; i++) {
      // Mutable state
      samplingMoveBuilder
      .add(normalMoves.asList().get(new Random().nextInt(normalMoves.size())));
    }
    if (roundNum + 1 > 3 && nearestPlayer < 2) {
      for (int i = 0; i < mrXSamples; i++) {
        samplingMoveBuilder
        .add(mrXMoves.asList().get(new Random().nextInt(mrXMoves.size())));
      }
    }

    

// Immutable State
var samplingMoves = samplingMoveBuilder.build();
System.out.println(samplingMoves.size());

    // takes a immutalbe list of moves works out the 'quality' of each and chooses the best
    samplingMoves.parallelStream().forEach(m -> {

      var destination = Library.moveDestination(m);
      var solution = new AStarMrX(board, Integer.valueOf(m.source()), destination);
      solution.getSolution();

      solutions.put(m, solution.nodeCostsMap().entrySet().stream().filter(n -> !n.getKey().equals(m.source()))
          .min((e1, e2) -> e1.getValue().compareTo(e2.getValue())).get().getValue());

      if (m.visit(new FunctionalVisitor<Boolean>(sm -> false, dm -> true))) {
        double value = solutions.get(m) * 1.5;
        solutions.remove(m);
        solutions.put(m, value);
      }

      //System.out.println(m + " -> " + solutions.get(m));
    });

    return getMinMove(solutions);
  }

  @Override
  public String name() {
    return "Test: Mr X";
  }

}