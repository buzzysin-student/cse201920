package uk.ac.bris.cs.scotlandyard.ui.ai.taharka.lib.traits;

import com.google.common.collect.ImmutableSet;
import com.google.common.graph.ValueGraph;

/**
 * A trait that allows the inherited class to calculate a nodal distance by
 * using the method {@link #nodalDistance}
 */
public interface CalculatesNodalDistance<V, E> {

  /**
   * Inner recursive implementation
   * 
   * @hidden
   * @param <V>
   * @param <E>
   * @param graph
   * @param accumulator
   * @param start
   * @param end
   * @param count
   * @return
   */
  default Integer _nodalDistance(ValueGraph<V, E> graph, ImmutableSet<V> accumulator, V start, V end, int count) {
    if (accumulator.contains(end))
      return count;

    var builder = ImmutableSet.<V>builder().addAll(accumulator);

    accumulator.forEach(acc -> {
      graph.adjacentNodes(acc).forEach(adj -> {
        if (accumulator.contains(adj))
          return;

        builder.add(adj);
      });
    });

    return _nodalDistance(graph, builder.build(), start, end, ++count);
  }

  /**
   * How many nodes between {@code start} and {@cod end}?
   * 
   * @param <V>   key type
   * @param <E>   edge type
   * @param graph the graph to query
   * @param start the starting node
   * @param end   the ending node
   * @return the number of nodes between {@code start} and {@code end}
   */
  public default Integer nodalDistance(ValueGraph<V, E> graph, V start, V end) {
    var accumulator = ImmutableSet.of(start);
    return _nodalDistance(graph, accumulator, start, end, 0);
  }
}