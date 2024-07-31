#include <algorithm> // For count function
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to determine if S can be converted to T in exactly K swaps
bool canConvert(const string &S, const string &T, int K, int N) {
  // Count mismatches
  int zeroToOne = 0, oneToZero = 0;
  for (int i = 0; i < N; ++i) {
    if (S[i] == '0' && T[i] == '1') {
      ++zeroToOne;
    }
    if (S[i] == '1' && T[i] == '0') {
      ++oneToZero;
    }
  }

  // Minimum swaps required is the maximum of zero-to-one and one-to-zero
  // mismatches
  int minSwapsRequired = max(zeroToOne, oneToZero);

  // Check if we can make exactly K swaps
  return K >= minSwapsRequired && (K - minSwapsRequired) % 2 == 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  vector<string> results;

  while (T--) {
    int N, K;
    cin >> N >> K;
    string S, T;
    cin >> S >> T;
    if (canConvert(S, T, K, N)) {
      results.push_back("YES");
    } else {
      results.push_back("NO");
    }
  }

  // Output all results after processing all test cases
  for (const string &result : results) {
    cout << result << endl;
  }

  return 0;
}
