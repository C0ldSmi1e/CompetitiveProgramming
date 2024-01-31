/**
 * Author: C0ldSmi1e
 * Created Time: 01/06/2024 06:52:09 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1919/problem/C
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    int res = 0;
    int x = n + 1, y = n + 1;
    for (int i = 0; i < n; i++) {
      if (max(x, y) < a[i]) {
        res += 1;
        if (x < y) {
          x = a[i];
        } else {
          y = a[i];
        }
      } else if (min(x, y) >= a[i]) {
        if (x < y) {
          x = a[i];
        } else {
          y = a[i];
        }
      } else {
        if (x > y) {
          x = a[i];
        } else {
          y = a[i];
        }
      }
      debug(x, y, res);
    }
    cout << res << '\n';
  }
  return 0;
}
