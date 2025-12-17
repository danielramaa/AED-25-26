// -------------------------------------------------------------
// Algorithms and Data Structures 2025/2026 - LEIC (FCUP/FEUP)
// http://www.dcc.fc.up.pt/~pribeiro/aulas/aed2526/
// -------------------------------------------------------------
// A simple lightweight graph class
// Last update: 24/11/2024
// -------------------------------------------------------------

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>

class Graph {
  struct Edge {
    int dest;   // Destination node 
    int weight; // An integer weight
  };
	
  struct Node {
    std::list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
    bool visited;        // Has the node been visited in a graph traversal?
  };
	
  int n;                   // Graph size (vertices are numbered from 1 to n)
  bool hasDir;             // false: undirected; true: directed
  std::vector<Node> nodes; // The list of nodes being represented
	
public:  
  // Constructor: nr nodes and direction (default: undirected)
  Graph(int num, bool dir = false) : n(num), hasDir(dir), nodes(num+1) {}
  
  // Add edge from source to destination with a certain weight
  void addEdge(int src, int dest, int weight = 1) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
  }
  
  // --------------------------------------------------------------
  
  // Read a graph in the format:
  // nr_nodes directed/undirected weighted/unweighted
  // nr_edges
  // src_1 dest_1 <weight_1>
  // src_2 dest_2 <weight_2>
  // ...
  // src_n dest_n <weight_n>
  static Graph *readGraph() {
    int n;
    std::string sdirection, sweight;
    std::cin >> n >> sdirection >> sweight;  
    bool directed = (sdirection == "directed")?true:false;
    bool weighted = (sweight == "weighted")?true:false;
  
    Graph *g = new Graph(n, directed);
    int e;
    std::cin >> e;
    for (int i=0; i<e; i++) {
      int u, v, w = 1;
      std::cin >> u >> v;
      if (weighted) std::cin >> w;
      g->addEdge(u, v, w);
    }
    return g;
  }

  // --------------------------------------------------------------
  // Depth-First Search (DFS): example implementation
  // --------------------------------------------------------------
  int dfs(int v) {
    int count = 1;
    // std::cout << v << " "; // show node order
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
      int w = e.dest;
      if (!nodes[w].visited)
        count += dfs(w);
    }
    return count;
  }
  
  // --------------------------------------------------------------
  // Breadth-First Search (BFS): example implementation
  // --------------------------------------------------------------
  void bfs(int v) {
    for (int i=1; i<=n; i++) nodes[i].visited = false;
    std::queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
      int u = q.front(); q.pop();      
      std::cout << u << " ";  // show node order
      for (auto e : nodes[u].adj) {
        int w = e.dest;
        if (!nodes[w].visited) {
          q.push(w);
          nodes[w].visited = true;
        }
      }
    }
  }
  
  
  // --------------------------------------------------------------

  // ---------------------------------------------------------
  // TODO: put the functions you need to implement below this
  // ---------------------------------------------------------

  int nrConnectedComponents() {
    int count = 0;
    for (int i=1; i<=n; i++) nodes[i].visited = false;

    for (int i=1; i<=n; i++) {
        if (!nodes[i].visited) {
            count++; 
            dfs(i);
        }
    }
    return count;
  }


  int largestComponent() {
    int maxSize = 0;
    for (int i=1; i<=n; i++) nodes[i].visited = false;

    for (int i=1; i<=n; i++) {
        if (!nodes[i].visited) {
            int size = dfs(i);
            if (size > maxSize) maxSize = size;
        }
    }
    return maxSize;
  }

  void dfsTopo(int v, std::list<int>& order) {
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
      int w = e.dest;
      if (!nodes[w].visited) {
        dfsTopo(w, order);
      }
    }
    order.push_front(v);
  }

  std::list<int> topologicalSorting() {
    std::list<int> order;
    for (int i = 1; i <= n; i++) nodes[i].visited = false;
    
    for (int i = 1; i <= n; i++) {
      if (!nodes[i].visited) {
        dfsTopo(i, order);
      }
    }
    return order;
  }

  bool dfsCycle(int v, std::vector<int> &color) {
    color[v] = 1; 
    for (auto e : nodes[v].adj) {
      int w = e.dest;
      if (color[w] == 1) return true;
      if (color[w] == 0) {
        if (dfsCycle(w, color)) return true;
      }
    }
    color[v] = 2;
    return false;
  }

  bool hasCycle() {
    std::vector<int> color(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      if (color[i] == 0) {
        if (dfsCycle(i, color)) return true;
      }
    }
    return false;
  }

  bool isBipartite() {
    std::vector<int> color(n + 1, 0); // 0: uncolored, 1: color A, 2: color B
    std::queue<int> q;
    
    // Since the graph is guaranteed to be connected, we can start from node 1
    int startNode = 1;
    color[startNode] = 1;
    q.push(startNode);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (auto e : nodes[u].adj) {
            int v = e.dest;
            if (color[v] == 0) {
                color[v] = (color[u] == 1) ? 2 : 1;
                q.push(v);
            } else if (color[v] == color[u]) {
                return false;
            }
        }
    }
    
    return true;
  }
  
};

#endif

