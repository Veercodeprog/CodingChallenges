
#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
  int T;
  cin >> T;
  while (T--) {
    int N, K;
    cin >> N >> K;
    string S, T;
    cin >> S >> T;

    // Frequency check
    array<int, 2> count_s{}, count_t{};
    for (auto c : S)
      count_s[c - '0']++;
    for (auto c : T)
      count_t[c - '0']++;

    if (count_s != count_t) {
      cout << "NO\n";
      continue;
    }

    // Calculate mismatches
    int count_diff = 0;
    for (int i = 0; i < N; ++i) {
      if (S[i] != T[i])
        count_diff++;
    }

    // Calculate minimum moves needed
    int min_moves = count_diff / 2;

    if (min_moves > K) {
      cout << "NO\n";
      continue;
    }

    // Check if extra moves are possible
    bool single_moves_possible = count_s[0] >= 2 || count_s[1] >= 2;
    if ((K - min_moves) % 2 == 1 && !single_moves_possible) {
      cout << "NO\n";
      continue;
    }

    cout << "YES\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
