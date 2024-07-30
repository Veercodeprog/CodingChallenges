// memoized fibonacci (using cache)
//
#include <iostream>
#include <unordered_map>
using namespace std;

// Memoized Fibonnaci (passing memo or cache as a parameter)

int fibonnaciMemoized(int n, unordered_map<int, int> &memo) {
  if (memo.find(n) != memo.end()) { // if n is in memo
    // memo.end(): If the key is not found, memo.find(key) returns memo.end(),
    // indicating that the key is not present in the map.
    return memo[n];
  }

  if (n <= 2) {
    return 1;
  } else {
    int result =
        fibonnaciMemoized(n - 1, memo) + fibonnaciMemoized(n - 2, memo);
    return memo[n] = result;
  }
}

unordered_map<int, int> cache;

int fibonacciMaster(int n) {

  if (cache.find(n) != cache.end()) {
    return cache[n];
  }

  if (n <= 2) {
    return 1;
  } else {
    cache[n] = fibonacciMaster(n - 1) + fibonacciMaster(n - 2);
    return cache[n];
  }
}

int main() {
  cout << fibonacciMaster(50) << endl;
  return 0;
}
