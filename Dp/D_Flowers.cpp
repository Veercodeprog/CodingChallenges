#include <iostream>
#include <unordered_map>
#include <vector>
#define MOD 1000000007
using namespace std;
// using tabulation
long long countWaysTab(int a, int b, int k) {
  int maxN = max(a, b);
  vector<long long> dp(maxN + 1, 0); //
  dp[0] = 1;
  for (int i = 1; i <= maxN; i++) {
    dp[i] = dp[i - 1];
    if (i >= k) {
      dp[i] += dp[i - k];
      dp[i] %= MOD;
    }
  }

  long long result = 0;
  if (a == b) {
    result = dp[a];
    return result;
  }
  for (int i = a; i <= b; i++) {
    result += dp[i];
    result %= MOD;
  }
  return result;
}

// using memoization
//
void precomputeWays(vector<long long> &dp, vector<long long> &prefixSum,
                    int maxN, int k) {
  dp[0] = 1;
  for (int i = 1; i <= maxN; i++) {
    dp[i] = dp[i - 1];
    if (i >= k) {
      dp[i] += dp[i - k];
    }
    dp[i] %= MOD;
  }
  for (int i = 1; i <= maxN; i++) {
    prefixSum[i] = (prefixSum[i - 1] + dp[i]) % MOD;
  }
}

int main() {
  int t, k;
  cin >> t >> k;

  vector<pair<int, int>> testCases(t);
  int maxB = 0;
  for (int i = 0; i < t; ++i) {
    cin >> testCases[i].first >> testCases[i].second;
    if (testCases[i].second > maxB) {
      maxB = testCases[i].second;
    }
  }

  unordered_map<int, long long> memo;
  vector<long long> dp(maxB + 1, 0);
  vector<long long> prefixSum(maxB + 1, 0);

  // Precompute the number of ways
  precomputeWays(dp, prefixSum, maxB, k);

  for (const auto &testCase : testCases) {
    int a = testCase.first;
    int b = testCase.second;

    if (memo.find(b) == memo.end()) {
      memo[b] = prefixSum[b];
    }

    long long result = (memo[b] - (a > 1 ? prefixSum[a - 1] : 0) + MOD) % MOD;
    cout << result << endl;
  }

  return 0;
}
