/**
 * Author: C0ldSmi1e
 * Created Time: 01/27/2024 06:56:19 AM
**/

// time-limit: 1500
// problem-url: https://codeforces.com/contest/1925/problem/B
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
    int x, n;
    cin >> x >> n;
    int res = 0;
    for (int i = 1; i <= x / i; i++) {
      if (x % i == 0) {
        if (i >= n) {
          res = max(res, x / i);
        }
        if (x / i >= n) {
          res = max(res, i);
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}
