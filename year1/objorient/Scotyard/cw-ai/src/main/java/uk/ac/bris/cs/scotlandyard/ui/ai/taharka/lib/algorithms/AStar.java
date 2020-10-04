package uk.ac.bris.cs.scotlandyard.ui.ai.taharka.lib.algorithms;

import com.google.common.collect.ImmutableMap;
import com.google.common.collect.ImmutableSet;
import com.google.common.graph.ValueGraph;

import uk.ac.bris.cs.scotlandyard.model.ScotlandYard.Transport;
import uk.ac.bris.cs.scotlandyard.ui.ai.taharka.lib.algorithms.AbstractSolver.Node;
import uk.ac.bris.cs.scotlandyard.ui.ai.taharka.lib.traits.CalculatesNodalDistance;

/**
 * <h3>A*</h3>
 * 
 * The A* Algorithm finds the shortest path by assigning nodes heuristic values
 * and determining a cost for each node. A common pair of heuristics are the
 * distance from the node to both this sink and source node
 * 
 * @author Taharka N. Okai
 */
public class AStar extends AbstractSolver<Integer, ImmutableSet<Transport>>
    implements CalculatesNodalDistance<Node<Integer>, ImmutableSet<Transport>> {

  public AStar(ValueGraph<Integer, ImmutableSet<Transport>> original, Integer start, Integer end) {
    super(original, start, end);
  }

  @Override
  protected Double edgeFunction(ImmutableSet<Transport> edge) {
    return null;
  }

  @Override
  protected Double costFunction(ValueGraph<Node<Integer>, ImmutableSet<Transport>> nodeGraph, Node<Integer> prev,
      Node<Integer> next) {
    return prev.cost + (double) (
    /*  */nodalDistance(nodeGraph, fetchNode(start(), nodeGraph).get(), next) // nodal distance from start
        + nodalDistance(nodeGraph, fetchNode(end(), nodeGraph).get(), next) // nodal distance from end
    );
  }

  @Override
  protected Double getDefaultNodeValue() {
    return Double.POSITIVE_INFINITY;
  }

  @Override
  protected Double getSourceNodeValue() {
    return 0d;
  }

  @Override
  protected final void solveIntermediate() {
    var terminate = intermediateGraph().nodes().stream().filter(n -> n.locked).anyMatch(n -> n.id.equals(end()));
    if (!terminate) {
      var next = findNextSolvableNode(intermediateGraph()).get().locked(true);
      intermediateGraph().adjacentNodes(next).stream().filter(n -> !n.locked).forEach(adj -> {
        adj.cost(costFunction(intermediateGraph(), next, adj));
      });
      solveIntermediate();
    }
  }

  public ImmutableMap<Integer, Double> nodeCostsMap() {
    var map = ImmutableMap.<Integer, Double>builder();
    intermediateGraph().nodes().stream().forEach(n -> {
      map.put(n.id, n.cost);
    });
    return map.build();
  }

}