/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-02 11:06:53
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc331/tasks/abc331_b
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

  int n, s, m, l;
  cin >> n >> s >> m >> l;
  int res = (int) 2e9;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        if (i * 6 + j * 8 + k * 12 >= n) {
          res = min(res, s * i + m * j + l * k);
        }
      }
    }
  }
  cout << res << '\n';
  return 0;
}
