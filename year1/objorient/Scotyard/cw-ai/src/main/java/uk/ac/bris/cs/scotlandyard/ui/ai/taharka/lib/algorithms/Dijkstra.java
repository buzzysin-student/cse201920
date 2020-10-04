package uk.ac.bris.cs.scotlandyard.ui.ai.taharka.lib.algorithms;

import com.google.common.collect.ImmutableMap;
import com.google.common.collect.ImmutableSet;
import com.google.common.graph.ValueGraph;

import uk.ac.bris.cs.scotlandyard.model.ScotlandYard.Transport;

/**
 * <h3>Dijkstra's Algorithm</h3>
 * 
 * Dijkstra's Algorithm finds the shortest path by inhently creating a tree
 * structure, extending it via short edges until it reaches the sink node (end)
 * 
 * @author Taharka N. Okai
 */
public class Dijkstra extends AbstractSolver<Integer, ImmutableSet<Transport>> {

  public Dijkstra(ValueGraph<Integer, ImmutableSet<Transport>> original, Integer start, Integer end) {
    super(original, start, end);
  }

  @Override
  protected Double costFunction(ValueGraph<Node<Integer>, ImmutableSet<Transport>> nodeGraph, Node<Integer> prev,
      Node<Integer> next) {
    return prev.cost + edgeFunction(nodeGraph.edgeValue(next, prev).get());
  }

  @Override
  protected Double edgeFunction(ImmutableSet<Transport> edge) {
    return edge.stream().map(t -> (double) (Transport.values().length - t.ordinal())).reduce(Double::sum).get();
  }

  @Override
  protected Double getDefaultNodeValue() {
    return Double.POSITIVE_INFINITY;
  }

  @Override
  protected Double getSourceNodeValue() {
    return 0d;
  }

  public ImmutableMap<Integer, Double> nodeCostsMap() {
    var map = ImmutableMap.<Integer, Double>builder();
    intermediateGraph().nodes().stream().forEach(n -> {
      map.put(n.id, n.cost);
    });
    return map.build();
  }
  
}