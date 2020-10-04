package uk.ac.bris.cs.scotlandyard.ui.ai.taharka.lib.algorithms;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;
import com.google.common.graph.ValueGraph;

import uk.ac.bris.cs.scotlandyard.model.Board;
import uk.ac.bris.cs.scotlandyard.model.Piece.Detective;
import uk.ac.bris.cs.scotlandyard.model.ScotlandYard.Transport;

public class AStarMrX extends AStar {

  private Board board;

  public AStarMrX(Board board, Integer start, Integer end) {
    super(board.getSetup().graph, start, end);
    this.board = board;
  }

  public ImmutableList<Integer> detectiveLocations() {
    return board.getPlayers().stream()/*  */
        .filter(p -> p.isDetective())/*  */
        .map(p -> board.getDetectiveLocation((Detective) p).get())/*  */
        .collect(ImmutableList.toImmutableList());
  }

  @Override
  protected Double costFunction(ValueGraph<Node<Integer>, ImmutableSet<Transport>> nodeGraph, Node<Integer> prev,
      Node<Integer> next) {
    return prev.cost
        - Math.pow(/*  */
            detectiveLocations().stream()
                .map(location -> (double) nodalDistance(nodeGraph, fetchNode(location, nodeGraph).get(), next))
                .reduce(Double::sum).get(),
            2) /* + 2 * super.costFunction(nodeGraph, prev, next) */;
  }

  @Override
  public void solve() {
    super.solve();
  }

}