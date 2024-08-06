#include <iostream>
#include <string>
#include <vector>

const unsigned int MOD = 998244353;

int binaryStringToInt(const std::string &binaryString) {
  unsigned int result = 0;
  for (char c : binaryString) {
    result = (result << 1) | (c - '0');
  }
  return result;
}
std::string removeLastDigit(const std::string &binaryString) {
  if (binaryString.empty()) {
    return binaryString; // Handle empty input
  }

  // Remove the last character from the string
  return binaryString.substr(0, binaryString.length() - 1);
}
int main() {
  int n, m;
  std::cin >> n >> m;
  std::string binaryString;
  std::string binaryString1;
  std::cin >> binaryString;
  std::cin >> binaryString1;

  // Convert binary strings to integers
  unsigned int a = binaryStringToInt(binaryString);
  unsigned int b = binaryStringToInt(binaryString1);

  int result = 0;
  for (int i = 0; i < m; i++) {
    unsigned int b = binaryStringToInt(binaryString1);
    result = a & b;

    result = result % MOD;
    binaryString1 = removeLastDigit(binaryString1);
  }
  std::cout << result << std::endl;
}
