// id = 45311800
#include <iostream>
#include <vector>

typedef int Vertex;  // to differentiate vertices from numbers

// Returns the total distance from vertex to all the vertices of its subtree
int DFS(Vertex vertex, std::vector<std::vector<Vertex>> successor,
        std::vector<int>& number_of_subtree_vertices) {
  int total_distance = 0;
  for (auto son_of_vertex : successor[vertex]) {
    total_distance += DFS(son_of_vertex, successor, number_of_subtree_vertices) +
                      number_of_subtree_vertices[son_of_vertex];
    number_of_subtree_vertices[vertex] += number_of_subtree_vertices[son_of_vertex];
  }
  ++number_of_subtree_vertices[vertex];
  return total_distance;
}

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<std::vector<Vertex>> successor(n);  // represents the tree
  std::vector<Vertex> predecessor(n);
  Vertex parent = 0;
  Vertex son = 0;
  for (int i = 0; i < n - 1; ++i) {
    std::cin >> parent >> son;
    if (parent > son) {
      std::swap(parent, son);
    }
    successor[parent].push_back(son);
    predecessor[son] = parent;
  }
  std::vector<int> distance(n);
  std::vector<int> number_of_subtree_vertices(n);
  distance[0] = DFS(0, successor, number_of_subtree_vertices);
  std::cout << distance[0] << std::endl;
  for (Vertex vertex = 1; vertex < n; ++vertex) {
    // This formula can be checked easily
    distance[vertex] += distance[predecessor[vertex]] - number_of_subtree_vertices[vertex] + n -
                        number_of_subtree_vertices[vertex];
    std::cout << distance[vertex] << std::endl;
  }
  return 0;
}
