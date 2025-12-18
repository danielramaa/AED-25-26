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
  void dfs(int v) {
    std::cout << v << " "; // show node order
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
      int w = e.dest;
      if (!nodes[w].visited)
        dfs(w);
    }
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

  
  int distance(int a, int b) {
    if (a == b) return 0;
    std::vector<int> d(n + 1, -1);
    std::queue<int> q;
    q.push(a);
    d[a] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (u == b) return d[u];
      for (auto e : nodes[u].adj) {
        int w = e.dest;
        if (d[w] == -1) {
          d[w] = d[u] + 1;
          q.push(w);
        }
      }
    }
    return -1;
  }

  int diameter() {
    if (n == 0) return 0;
    
    // Check if connected
    for (int i=1; i<=n; i++) nodes[i].visited = false;
    int count = 0;
    std::queue<int> q;
    q.push(1);
    nodes[1].visited = true;
    count++;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (auto e : nodes[u].adj) {
        int w = e.dest;
        if (!nodes[w].visited) {
          nodes[w].visited = true;
          q.push(w);
          count++;
        }
      }
    }
    if (count < n) return -1;

    int max_d = 0;
    for (int i=1; i<=n; i++) {
      std::vector<int> d(n+1, -1);
      std::queue<int> q;
      q.push(i);
      d[i] = 0;
      while (!q.empty()) {
        int u = q.front(); q.pop();
        if (d[u] > max_d) max_d = d[u];
        for (auto e : nodes[u].adj) {
          int w = e.dest;
          if (d[w] == -1) {
            d[w] = d[u] + 1;
            q.push(w);
          }
        }
      }
    }
    return max_d;
  }

  std::list<int> shortestPath(int a, int b) {
    std::list<int> path;
    if (a == b) {
        path.push_back(a);
        return path; 
    }

    // BFS to compute distances
    std::vector<int> d(n + 1, -1);
    std::queue<int> q;
    
    d[a] = 0;
    q.push(a);
    
    bool found = false;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u == b) {
            found = true;
            break;
        }
        for(auto& e : nodes[u].adj){
            int v = e.dest;
            if(d[v] == -1){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    if(d[b] == -1) return path; // Empty list

    // Reconstruct path
    int curr = b;
    path.push_front(curr);
    while(curr != a) {
        int next_node = -1;
        
        if (!hasDir) {
            // Undirected: check neighbors of curr
            int min_v = -1;
            for (auto& e : nodes[curr].adj) {
                int v = e.dest;
                if (d[v] == d[curr] - 1) {
                    if (min_v == -1 || v < min_v) {
                        min_v = v;
                    }
                }
            }
            next_node = min_v;
        } else {
            // Directed: check all nodes to see which one points to curr
            for (int v = 1; v <= n; v++) {
                if (d[v] == d[curr] - 1) {
                    // Check if edge v -> curr exists
                    bool hasEdge = false;
                    for (auto& e : nodes[v].adj) {
                        if (e.dest == curr) {
                            hasEdge = true;
                            break;
                        }
                    }
                    if (hasEdge) {
                        next_node = v;
                        break; // Found smallest v
                    }
                }
            }
        }
        
        if (next_node != -1) {
            curr = next_node;
            path.push_front(curr);
        } else {
            break; 
        }
    }
    
    return path;
  }



  
};

#endif

