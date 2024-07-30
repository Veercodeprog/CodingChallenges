/*
* Problem Statement
Title: Solving Hidden Test Cases for Coding Problem

You are given two strings:

String A consisting of lowercase English letters.
String B consisting of lowercase English letters.
Your task is to determine if string B can be a subsequence of string A by
changing at most one character in B (except the first character). If it is
possible, find the first index (1-based) where B can be found as a subsequence
in A. If not found, output -1.

Constraints
1≤𝑇≤10^2
Strings A and B consist of only lowercase English letters.
Example
Input:
1
daabe
abe

Output:
2

*/

#include <iostream>
#include <string>

using namespace std;

bool isSubsequence(const string &A, const string &B, int start) {
  int m = B.size();

  int j = 0;
  for (int i = start; i < A.size() && j < m; i++) {
    if (A[i] == B[j]) {
      j++;
    }
  }
  return j == m;
}

bool canBeSequenceWithOneChange(string A, const string &B, int start) {
  int m = B.size();
  if (start + m > A.size()) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    if (A[start + i] != B[i]) {
      char originalChar = A[start + i];
      A[start + i] = B[i];
      if (isSubsequence(A, B, start)) {
        return true;
      }
      A[start + i] = originalChar; // restore the original character
    }
  }
  return false;
}

int firstIndex(string A, string &B) {
  int n = A.size();
  int m = B.size();

  for (int i = 0; i <= n - m; i++) {
    if (A[i] == B[0]) {
      if (isSubsequence(A, B, i)) {
        return i + 1;
      }
      elseif(canBeSequenceWithOneChange(A, B, i)) { return i + 1; }
    }
  }
  return -1;
}
int main() {
  while (true) {
    string A, B;
    cout << "Enter string A: ";
    cin >> A;
    cout << "Enter string B: ";
    cin >> B;
    int result = firstIndex(A, B);
    if (result == -1) {
      cout << "Output: -1" << endl;
    } else {
      cout << "Output: " << result << endl;
    }
    char continueInput;
    cout << "Do you want to enter another test case? (y/n): ";
    cin >> continueInput;
    if (continueInput != 'y' && continueInput != 'Y') {
      break;
    }
  }

  return 0;
}
