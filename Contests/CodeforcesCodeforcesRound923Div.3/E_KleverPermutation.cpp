/**
 * Author: C0ldSmi1e
 * Created Time: 02/06/2024 07:55:51 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1927/problem/E
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> b(n);
    for (int i = 0, l = 0, r = n + 1; i < k; i++) {
      for (int j = i; j < n; j += k) {
        if (i & 1) {
          b[j] = --r;
        } else {
          b[j] = ++l;
        }
      }
    }
    for (auto& u : b) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
