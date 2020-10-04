package uk.ac.bris.cs.scotlandyard.ui.ai.taharka.lib.algorithms;

import com.google.common.collect.ImmutableSet;
import com.google.common.graph.ValueGraph;

import uk.ac.bris.cs.scotlandyard.model.Board;
import uk.ac.bris.cs.scotlandyard.model.ScotlandYard.Transport;

public class AStarDetective extends AStarMrX {

  public AStarDetective(Board board, Integer start, Integer end) {
    super(board, start, end);
  }

  @Override
  protected Double costFunction(ValueGraph<Node<Integer>, ImmutableSet<Transport>> nodeGraph, Node<Integer> prev,
      Node<Integer> next) {
    return 1 / super.costFunction(nodeGraph, prev, next);
  }

}