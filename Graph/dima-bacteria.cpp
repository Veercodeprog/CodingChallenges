#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = INT_MAX;
const int MAXN = 100005;            // Adjust based on problem constraints
vector<pair<int, int>> graph[MAXN]; // adjacency list for the graph

// pair<int, int>: A pair is a simple container from the C++ Standard Library
// that holds two values.
//
void floydWarshall(int n, vector<vector<int>> &dist) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dist[i][j] = INF;
    }
    dist[i][i] = 0;
  }

  for (int u = 1; u <= n; ++u) {
    for (auto [v, cost] : graph[u]) {
      dist[u][v] = cost;
      dist[v][u] = cost;
    }
    for (int k = 1; k <= n; ++k) {
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          if (dist[i][k] < INF && dist[k][j] < INF) {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
          }
        }
      }
    }
  }
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> types(n + 1); // vactor with n+1 element as we waant to use 1
                            // based indexing for the vectory of
  vector<vector<int>> bacteria_of_type(k + 1);
  // bacteria_of_type(k + 1): This creates a vector with k + 1 elements, where
  // each element is an empty vector<int>.

  // vector<vector<pair<int, int>>> adj(n + 1); // adjacency list
  // it is vector of vector of pair as we want to store the weight of the edge
  // as well its strructture is adj[1] = { {2, 3}, {3, 4} } means there is an
  // edge from 1 to 2 with weight 3 and from 1 to 3 with weight

  // for number of bacteria of each typei
  int totalCount;

  for (int i = 1; i <= k; i++) {

    int count;
    if (totalCount > n) {
      cout << "bacterias exceed the total number of bacteria i.e n" << endl;
      return 0;
    }

    cin >> count;
    totalCount += count;
    for (int j = 0; j < count; ++j) {
      int bact;
      cin >> bact;
      bacteria_of_type[i].push_back(bact);
      types[bact] = i; // Assign type to bacteria
    }
  }

  for (int i = 0; i < m; i++) {

    int u, v, w;
    cin >> u >> v >> w;
    graph[u].emplace_back(v, w);
    graph[v].emplace_back(u, w); // emplace_back is a function that adds an
                                 //  element to the end of a vector
  }
  vector<vector<int>> dist(
      n + 1, vector<int>(n + 1)); // vector of type vector with n+1 rows and
                                  // each row has vector of n+1 elements
  floydWarshall(n, dist);
  vector<vector<int>> d(k + 1, vector<int>(k + 1, -1));
  bool has_zero_cost_pair = false;

  // Fill the k x k matrix d based on the distance matrix
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= k; ++j) {
      bool found_zero = false;
      for (int u : bacteria_of_type[i]) {
        for (int v : bacteria_of_type[j]) {
          if (dist[u][v] == 0) {
            found_zero = true;
            break;
          }
        }
        if (found_zero)
          break;
      }
      d[i][j] = found_zero ? 0 : -1;
      if (found_zero) {
        has_zero_cost_pair = true;
      }
    }
  }

  if (has_zero_cost_pair) {
    cout << "Yes\n";
    for (int i = 1; i <= k; ++i) {
      for (int j = 1; j <= k; ++j) {
        cout << d[i][j] << " ";
      }
      cout << "\n";
    }
  } else {
    cout << "No\n";
  }
}
