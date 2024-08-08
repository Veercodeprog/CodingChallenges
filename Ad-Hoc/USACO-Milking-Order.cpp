/*
 * https://usaco.org/index.php?page=viewproblem2&cpid=832
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n, m, k;
  cin >> n >> m >> k;
  int arr[m];
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    arr[i] = x;
  }
  vector<int> order(n, -1);

  for (int i = 0; i < k; i++) {
    int ci, pi;
    cin >> ci >> pi;
    order[pi - 1] = ci;
    if (ci == 1) {
      cout << pi << endl;
      return 0;
    }
  }
}
