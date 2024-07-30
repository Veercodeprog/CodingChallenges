/*
 * https://www.codechef.com/problems/CONVERT?tab=statement
 */

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool canConvert(const string &S, const string &T, int K, int N) {
  // Frequency check
  int countS0 = count(S.begin(), S.end(), '0');
  int countS1 = N - countS0; // Total length minus countS0 gives countS1
  int countT0 = count(T.begin(), T.end(), '0');
  int countT1 = N - countT0; // Total length minus countT0 gives countT1

  // If counts of '0' and '1' don't match, conversion is not possible
  if (countS0 != countT0 || countS1 != countT1) {
    return false;
  }

  // Calculate mismatches
  int zeroto1 = 0; // Number of positions where S has '0' and T has '1'
  int oneto0 = 0;  // Number of positions where S has '1' and T has '0'
  for (int i = 0; i < N; ++i) {
    if (S[i] == '0' && T[i] == '1')
      zeroto1++;
    if (S[i] == '1' && T[i] == '0')
      oneto0++;
  }

  // Minimum swaps required to fix all mismatches
  int minSwapsRequired = max(zeroto1, oneto0);

  // Check if K swaps can convert S to T
  if (K < minSwapsRequired) {
    return false;
  }

  // Calculate the remaining moves after the minimum required swaps
  int extraMoves = K - minSwapsRequired;

  // Check if single moves are possible if extra moves are odd
  // We need at least one pair of identical elements in S to perform single
  // moves
  bool singleMovesPossible = (countS0 >= 2 || countS1 >= 2);

  // The extra moves must be even, or if odd, we must be able to perform single
  // moves
  return (extraMoves % 2 == 0 || singleMovesPossible);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    int N, K;
    cin >> N >> K;
    string S, T;
    cin >> S >> T;

    cout << (canConvert(S, T, K, N) ? "YES" : "NO") << endl;
  }

  return 0;
}
