package sheet4;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.stream.Collectors;

import com.google.common.graph.EndpointPair;
import com.google.common.graph.ImmutableValueGraph;
import com.google.common.graph.ImmutableValueGraph.Builder;
import com.google.common.graph.ValueGraphBuilder;

@SuppressWarnings("UnstableApiUsage")
public class Search {

  // reads in a graph stored in plan text
  static ImmutableValueGraph<Integer, Integer> readGraph(String content) {
    List<String> lines = content.lines().collect(Collectors.toList());
    if (lines.isEmpty())
      throw new IllegalArgumentException("No lines");
    int currentLine = 0;

    String[] topLine = lines.get(currentLine++).split(" ");
    int numberOfNodes = Integer.parseInt(topLine[0]);
    int numberOfEdges = Integer.parseInt(topLine[1]);

    Builder<Integer, Integer> builder = ValueGraphBuilder.undirected().expectedNodeCount(numberOfNodes).immutable();

    for (int i = 0; i < numberOfNodes; i++) {
      String line = lines.get(currentLine++);
      if (line.isEmpty())
        continue;
      builder.addNode(Integer.parseInt(line));
    }

    for (int i = 0; i < numberOfEdges; i++) {
      String line = lines.get(currentLine++);
      if (line.isEmpty())
        continue;

      String[] s = line.split(" ");
      if (s.length != 3)
        throw new IllegalArgumentException("Bad edge line:" + line);
      builder.putEdgeValue(Integer.parseInt(s[0]), Integer.parseInt(s[1]), Integer.parseInt(s[2]));
    }
    return builder.build();
  }

  /**
   * Lists all nodes values in a given graph.
   *
   * @param graph the graph to query the nodes from
   * @return lists of all the nodes in the given graph
   */
  static Collection<Integer> listAllNodes(ImmutableValueGraph<Integer, Integer> graph) {
    return graph.nodes();
  }

  /**
   * Lists all edge values in a given graph.
   *
   * @param graph the graph to query the edges from
   * @return lists of all the edges in the given graph
   */
  static Collection<Integer> listAllEdges(ImmutableValueGraph<Integer, Integer> graph) {
    // * Create a object that will be returned
    Collection<Integer> list = new ArrayList<Integer>();

    // * For each pair of nodes that are connected to the edge:
    for (EndpointPair<Integer> edge : graph.edges()) {
      // * Extract the item from the "Endpoint pair"
      Integer item = graph.edgeValue(edge).get();
      // * Add the item to the return "ArrayList"
      list.add(item);
    }

    // * Return the final ArrayList
    return list;
  }

  /**
   * Lists all nodes with 4 or more edges
   *
   * @param graph the graph to query the edges from
   * @return lists of all nodes that satisfy the condition
   */
  static Collection<Integer> findAllNodeWith4OrMoreEdges(ImmutableValueGraph<Integer, Integer> graph) {

    Collection<Integer> list = new ArrayList<Integer>();
    for (Integer node : graph.nodes()) {
      if (graph.adjacentNodes(node).size() >= 4) {
        list.add(node);
      }
    }
    return list;
  }

  /**
   * Lists all nodes with edges values that when summed, is > 20 For example, a
   * node with three connected edges: 1, 2, 3 has an edge sum of 6.
   *
   * @param graph the graph to query the edges from
   * @return lists of all nodes that satisfy the condition
   */
  static Collection<Integer> findAllNodesWithEdgeSumGreaterThan20(ImmutableValueGraph<Integer, Integer> graph) {
    // ? Find the nodes that...
    Collection<Integer> result = graph.nodes().stream()
        // ? have edges...
        .filter(node -> graph.incidentEdges(node).stream()
            // ? that add up to a number greater than 20...
            .map(edge -> graph.edgeValue(edge).get())
            // ? and return it as a list
            .reduce((acc, item) -> acc += item).get() > 20)
        .collect(Collectors.toList());

    return result;
  }

  /**
   * Finds the shortest possible path that travels from the source to destination,
   * factoring the edge distances. A path that allows you to travel from the
   * source to the destination with the minimum total edge distances is the
   * shortest path.
   *
   * @param graph       the graph to compute the shortest path with
   * @param source      the starting position of the search, the resulting list
   *                    should end with this value
   * @param destination the end position of the search, the resulting list should
   *                    end with this value
   * @return a list of nodes that represent the shortest path from source to
   *         destination
   */
  static List<Integer> shortestPathFromSourceToDestination(ImmutableValueGraph<Integer, Integer> graph, Integer source,
      Integer destination) {

    List<Integer> path = new ArrayList<Integer>();
    // Collection<Integer> nodes = graph.nodes();

    for (EndpointPair<Integer> edge : graph.incidentEdges(source)) {
      edge.adjacentNode(source);
    }

    return path;
  }

}
