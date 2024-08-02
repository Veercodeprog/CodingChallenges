#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100000 + 1;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<bool> ans(n + 1, false);

    // Read the input array
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Store positions based on values
    for (int i = 1; i <= n; ++i) {
        b[a[i]] = i;
    }

    // Determine the win/lose status
    for (int i = n; i >= 1; --i) {
        int pos = b[i];
        ans[pos] = false;

        // Check all positions j where the token can move from pos to the right
        for (int j = pos + a[pos]; j <= n; j += a[pos]) {
            if (a[j] > a[pos] && !ans[j]) {
                ans[pos] = true;
                break;
            }
        }

        // Check all positions j where the token can move from pos to the left
        for (int j = pos - a[pos]; j >= 1; j -= a[pos]) {
            if (a[j] > a[pos] && !ans[j]) {
                ans[pos] = true;
                break;
            }
        }
    }

    // Output the result
    for (int i = 1; i <= n; ++i) {
        cout << (ans[i] ? 'A' : 'B');
    }
    cout << endl;

    return 0;
}

