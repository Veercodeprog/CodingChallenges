#include <algorithm> // Include this header for the reverse function
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  ll n = s.length();
  vector<ll> a(n, 0);
  for (ll i = 0; i < s.length(); i++) {
    if (i != n - 1 && s[i] == 'b' && s[i + 1] == 'a')
      a[i] = 1;
    else if (s[i] == 'a' && (i == n - 1 || s[i + 1] == 'b'))
      a[i] = 1;
  }
  for (ll i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;

  return 0;
}
