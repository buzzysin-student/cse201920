package uk.ac.bris.cs.scotlandyard.ui.ai.taharka.lib.algorithms;

import java.util.function.Supplier;

import com.google.common.collect.ImmutableList;
import com.google.common.graph.ImmutableValueGraph;
import com.google.common.graph.MutableValueGraph;
import com.google.common.graph.ValueGraph;
import com.google.common.graph.ValueGraphBuilder;

/**
 * <h3>Generic implementation of a "shortest-path" algorithm on a graph</h3>
 * 
 * @author Taharka N. Okai
 * 
 * @param <V> the type of the (V)ertex of the graph
 * @param <E> the type of the (E)dges of the graph
 */
public abstract class AbstractSolver<V, E> {

  // Presets for any inherited class
  protected ValueGraph<Node<V>, E> builder = ValueGraphBuilder.undirected().build();
  protected boolean solved = false;
  protected ImmutableList<V> solution = ImmutableList.of();

  // Initialisable
  protected V start;
  protected V end;
  protected ValueGraph<V, E> original;
  private ValueGraph<Node<V>, E> intermediate;

  protected AbstractSolver(ValueGraph<V, E> original, V start, V end) {
    this.start = start;
    this.end = end;
    this.original = original;

    generateSolvableGraph();
    this.solution = ImmutableList.of(end);
    this.intermediate = intermediateGraph();

  }

  /**
   * @category CanOverride
   * @return the node that will act as the source node
   */
  protected V start() {
    return start;
  };

  /**
   * @category CanOverride
   * @return the node that will act as the sink node
   */
  protected V end() {
    return end;
  };

  /**
   * @category CanOverride
   * @return the graph for which to solve
   */
  protected ValueGraph<V, E> original() {
    return original;
  };

  /**
   * @category ShouldOverride
   * 
   * @description Default method for solving graph. Override for custom
   *              implementation
   */
  protected void solve() {
    solveIntermediate();
    solution = buildPath();
  }

  /**
   * @hidden
   */
  protected void solveIntermediate() {
    var terminate = intermediate.nodes().stream().filter(n -> n.locked).count() == intermediate.nodes().size();

    if (!terminate) {
      var next = findNextSolvableNode(intermediate).get().locked(true);
      intermediate.adjacentNodes(next).stream().filter(n -> !n.locked).forEach(adj -> {
        adj.cost(costFunction(intermediate, next, adj));
      });
      solveIntermediate();
    } 
  }

  /**
   * Determines the way the path is build from the result set
   * 
   * @param intermediate
   * @return
   */
  protected ImmutableList<V> buildPath() {
    while (!solution.contains(start())) {
      var solvedNode = fetchNode(solution.get(0), intermediate).get();
      var preceeding = intermediate.adjacentNodes(solvedNode).stream()/*  */
          .filter(n -> !solution.contains(n.id))/*  */
          .min(Node::compareCosts);

      if (preceeding.isPresent())
        solution = ImmutableList.<V>builder().add(preceeding.get().id).addAll(solution).build();
      else {
        System.err.println("There is an unhandled error with this solution.");
        return solution;
      }
    }
    return solution;
  }

  /**
   * @category CanOverride
   * @param id        the means by which a node is identified
   * @param nodeGraph the graph that the node belongs to
   * @return the node as it exists within graph wrapped around a {@code Supplier}
   */
  protected Supplier<Node<V>> fetchNode(V id, ValueGraph<Node<V>, E> nodeGraph) {
    return () -> nodeGraph.nodes().stream().filter(n -> n.id.equals(id)).findFirst().get();
  }

  /**
   * @category CanOverride
   * @return before build - accumulator for the graph; after build - an immutable
   *         graph
   */
  protected ValueGraph<Node<V>, E> intermediateGraph() {
    if (builder.nodes().size() != original().nodes().size())
      return builder;

    return ImmutableValueGraph.copyOf(builder);
  }

  /**
   * @category CanOverride
   * @description Stores intermediate nodes in {@code builder}
   */
  protected void generateSolvableGraph() {
    original().nodes().forEach(n -> {
      ((MutableValueGraph<Node<V>, E>) builder)
          .addNode(new Node<>(n, n.equals(start()) ? getSourceNodeValue() : getDefaultNodeValue()));
    });
    original().edges().forEach(e -> {
      ((MutableValueGraph<Node<V>, E>) builder).putEdgeValue(/*  */
          fetchNode(e.nodeU(), intermediateGraph()).get(), /*  */
          fetchNode(e.nodeV(), intermediateGraph()).get(), /*  */
          original().edgeValue(e).get());
    });
  }

  /**
   * @category CanOverride
   * @apiNote a Supplier is used in case the Node is mutated in the interim
   * @param nodeGraph use the nodeGraph to find the next solvable node in the next
   *                  recursive loop of the finder
   * @return a function that exposes the next node considered for computation
   */
  protected Supplier<Node<V>> findNextSolvableNode(ValueGraph<Node<V>, E> nodeGraph) {
    return () -> nodeGraph.nodes().stream().filter(n -> !n.locked).filter(n -> !n.cost.equals(getDefaultNodeValue()))
        .min(Node::compareCosts).get();
  }

  /**
   * @category CannotOverride
   * @return the set of nodes that lead to the shortest path
   */
  public final ImmutableList<V> getSolution() {
    if (!solved)
      solve();

    return solution;
  }

  // Mandatory configuration options

  /**
   * @category CanOverride
   * @param edge the edge on which to perform the computation
   * @return converts the edge value into a {@code Double}
   */
  protected abstract Double edgeFunction(E edge);

  /**
   * @category MustOverride
   * @param nodeGraph use the nodeGraph to pull values from the node-graph
   *                  otherwise inaccessible
   * @param prev      most recent calculated node
   * @param next      a node adjacent to the calculated node <b>that is to be
   *                  updated with this cost</b>
   * @return cost calculated from the graph, the recent node, the adjacent node
   *         and the edge that connects them
   */
  protected abstract Double costFunction(ValueGraph<Node<V>, E> nodeGraph, Node<V> prev, Node<V> next);

  /**
   * @category MustOverride
   * @return what value should nodes be initialised with?
   */
  protected abstract Double getDefaultNodeValue();

  /**
   * @category MustOverride
   * @return what value should the source node have by default?
   */
  protected abstract Double getSourceNodeValue();

  /**
   * The node that vertices {@code <V>} are mapped to in AbstractSolver<V, E>
   * 
   * @param <V> the label type
   * @apiNote for this to be used properly, V.toString() must be the same for any
   *          two instances of V with the same parameters
   */
  public static class Node<V> {
    public V id;
    public Double cost;
    protected Boolean locked = false;

    public Node(final V id, final Double cost) {
      this.id = id;
      this.cost = cost;
    }

    /**
     * Set {@code this.id} to {@code id}
     * 
     * @param id
     * @return this mutated node
     */
    public Node<V> id(V id) {
      this.id = id;
      return this;
    }

    /**
     * Set {@code this.cost} to {@code cost}
     * 
     * @param cost
     * @return this mutated node
     */
    public Node<V> cost(Double cost) {
      this.cost = cost;
      return this;
    }

    /**
     * Set {@code this.locked} to {@code locked}
     * 
     * @param locked
     * @return this mutated node
     */
    public Node<V> locked(Boolean locked) {
      this.locked = locked;
      return this;
    }

    /**
     * Helper method to compare costs for nodes
     * 
     * @param other the other node to compare to
     * @return reuse of <a href=java.lang.Double#compare>Double::compare</a>
     */
    public int compareCosts(final Node<V> other) {
      return Double.compare(cost, other.cost);
    }

    @Override
    public String toString() {
      return "Node(id=" + id.toString() + ", cost=" + cost + ")";
    }

    @Override
    public boolean equals(final Object other) {
      return this.toString().hashCode() == other.toString().hashCode();
    }

    @Override
    public int hashCode() {
      return super.hashCode();
    }
  }

}