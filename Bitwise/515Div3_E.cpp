
#include <bitset>
#include <iostream>
#include <sstream>
#include <string>

const unsigned int MOD = 998244353;

int main() {
  int n, m;
  std::cin >> n >> m;
  std::string binaryString;
  // std::cout << "Enter a binary string of lenght n: ";
  std::string binaryString1;
  std::cin >> binaryString;
  // std::cout << "Enter a binary string of length m: ";
  std::cin >> binaryString1;

  unsigned int a = std::bitset<1000000>(binaryString).to_ulong();
  unsigned int b = std::bitset<1000000>(binaryString1).to_ulong();

  int result = 0;
  for (int i = 0; i < m; i++) {
    result += a & b;
    result = result % MOD;
    b = b >> 1;
  }
  std::cout << result << std::endl;
}
