/*
 * https://usaco.org/index.php?page=viewproblem2&cpid=832
 */

#include <iostream>
#include <vector>

using namespace std;
int n, m, k;

bool check(vector<int> order, int arr[]) {
  vector<int> cow_to_pos(n, -1);
  for (int i = 0; i < n; i++) {
    if (order[i] != -1) {
      cow_to_pos[order[i]] = i; // position array based on cow indexing
    }
  }
  int h_idx = 0;
  for (int i = 0; i < n && h_idx < m; i++) {
    if (cow_to_pos[arr[h_idx]] != -1) {
      if (i > cow_to_pos[arr[h_idx]])
        return false;
      i = cow_to_pos[arr[h_idx]];
      h_idx++;
    } else {
      while (i < n && order[i] != -1)
        i++;
      if (i == n)
        return false;
      order[i] = arr[h_idx];
      cow_to_pos[arr[h_idx]] = i;
      h_idx++;
    }
  }
  return true;
}

int main() {

  cin >> n >> m >> k;
  int hierarchy[m];
  for (int i = 0; i < m; i++) {
    cin >> hierarchy[i];
    hierarchy[i]--;
  }
  vector<int> order(n, -1);

  for (int i = 0; i < k; i++) {
    int ci, pi;
    cin >> ci >> pi;

    order[--pi] = --ci;
    if (ci == 0) {
      cout << pi + 1 << endl;
      return 0;
    }
  }
  for (int j = m - 1; 0 <= j; j--) {
    if (order[j] == -1) {
      // try placicng cow 1 @ position j
      order[j] = 0;
      if (check(order, hierarchy)) {
        cout << j + 1 << endl;
        break;
      }
      order[j] = -1;
    }
  }
}
