#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
using ll = long long;
constexpr int INF = 0x3f3f3f3f; // Represents infinity

// Find the root of the set containing `x` using path compression
int findRoot(vector<int> &parent, const int &x) {
  if (parent[x] == x) {
    return x;
  } else {
    int root = findRoot(parent, parent[x]);
    parent[x] = root;
    return root;
  }
}

// Merge the sets containing `x` and `y`
void unionSets(vector<int> &parent, const int &x, const int &y) {
  int rootX = findRoot(parent, x);
  int rootY = findRoot(parent, y);
  if (rootX != rootY) {
    parent[rootX] = rootY;
  }
}
// Assign the same type to all bacteria in the range [left, right]
void assignType(vector<int> &typeAssignment, const int &left, const int &right,
                const int &type) {
  for (int i = left; i <= right; i++) {
    typeAssignment[i] = type;
  }
}
// Apply Floyd-Warshall algorithm to compute all-pairs shortest paths
void computeShortestPaths(vector<vector<int>> &distanceMatrix,
                          const int &size) {
  for (int k = 0; k < size; k++) {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (distanceMatrix[i][k] < INF && distanceMatrix[k][j] < INF) {
          distanceMatrix[i][j] =
              min(distanceMatrix[i][j],
                  distanceMatrix[i][k] + distanceMatrix[k][j]);
        }
      }
    }
  }
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (distanceMatrix[i][j] == INF) {
        distanceMatrix[i][j] = -1;
      }
    }
  }
}
bool areAllSameType(vector<int> &typeRoot, const int &left, const int &right) {
  int rootType = typeRoot[right];
  for (int i = left; i < right; i++) {
    if (typeRoot[i] != rootType) {
      return false;
    }
  }
  return true;
}
tuple<bool, vector<vector<int>>>
process(int numBacteria, int numConnections, int numTypes,
        const vector<int> &typeCounts,
        const vector<tuple<int, int, int>> &connections) {

  vector<int> parent(numBacteria + 1);
  for (int i = 1; i <= numBacteria; i++) {
    parent[i] = i;
  }

  for (const auto &[u, v, cost] : connections) {
    if (cost == 0) {

      unionSets(parent, u, v);
    }
  }

  vector<int> typeRoot(numBacteria + 1);
  for (int i = 1; i <= numBacteria; i++) {
    typeRoot[i] = findRoot(parent, i);
  }
  vector<int> typeAssignment(
      numBacteria +
      1); // for each bacteria, the type of the root of the set it belongs to
  int left = 1, right = 0;
  for (int type = 0; type < numTypes; type++) {
    right += typeCounts[type];
    bool allSame = areAllSameType(typeRoot, left, right);
    if (!allSame) {
      return {false, vector<vector<int>>(numTypes, vector<int>(numTypes, 0))};
    }
    assignType(typeAssignment, left, right, type);
    left = right + 1;
  }
  vector<vector<int>> distanceMatrix(numTypes, vector<int>(numTypes, INF));
  for (int type = 0; type < numTypes; type++) {
    distanceMatrix[type][type] = 0;
  }
  for (const auto &[u, v, cost] : connections) {
    int typeU = typeAssignment[u];
    int typeV = typeAssignment[v];
    distanceMatrix[typeU][typeV] = min(distanceMatrix[typeU][typeV], cost);
    distanceMatrix[typeV][typeU] = min(distanceMatrix[typeV][typeU], cost);
  }
  computeShortestPaths(distanceMatrix, numTypes);
  return {true, distanceMatrix};
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int numBacteria = 0, numConnections = 0, numTypes = 0;
  cin >> numBacteria >> numConnections >> numTypes;
  vector<int> typeCounts(numTypes, 0);
  for (int i = 0; i < numTypes; i++) {
    cin >> typeCounts[i];
  }
  vector<tuple<int, int, int>> connections;
  for (int i = 0; i < numConnections; i++) {
    int u = 0, v = 0, cost = 0;
    cin >> u >> v >> cost;
    connections.emplace_back(u, v, cost);
  }
  auto [isPossible, resultMatrix] =
      process(numBacteria, numConnections, numTypes, typeCounts, connections);
  if (isPossible) {
    cout << "Yes\n";
    for (int i = 0; i < numTypes; i++) {
      for (int j = 0; j < numTypes; j++) {
        cout << resultMatrix[i][j] << " ";
      }
      cout << "\n";
    }
  } else {
    cout << "No\n";
  }

  return 0;
}
