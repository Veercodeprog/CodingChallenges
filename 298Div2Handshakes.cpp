#include <iostream>
#include <unordered_map>
#include <vector>
// Function that checks possibility

// Function for order of entrance
bool orderOfEnterance(std::unordered_map<int, int> &a, int n) {
  std::vector<int> b(n);
  int recentHandshakes = 0;
  for (auto it = a.begin(); it != a.end(); it++) {
    if (it->second == 0 || recentHandshakes == 0 ||
        (it->second % 3 == 0 && it->second <= recentHandshakes + 1)) {
      b.push_back(it->first);
      recentHandshakes = it->second;
      it = a.erase(it);
    } else {
      return 0;
    }
    if (it->second == 1 ||
        (it->second % 3 == 1 && it->second <= recentHandshakes + 1)) {
      b.push_back(it->first);
      recentHandshakes = it->second;
      it = a.erase(it);
    } else {
      return 0;
    }
    if (it->second == 2 ||
        (it->second % 3 == 2 && it->second <= recentHandshakes + 1)) {
      b.push_back(it->first);
      recentHandshakes = it->second;
      it = a.erase(it);
    } else {
      return false;
    }
  }
  return true;
}
int main() {
  int n;
  std::cin >> n;

  std::unordered_map<int, int> a(n); // Dynamic array using vector
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  if (orderOfEnterance(a, n)) { // Pass the vector to the function
    std::cout << "Possible";
  } else {
    std::cout << "Impossible";
  }
}
