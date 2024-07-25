/**
 * Author: C0ldSmi1e
 * Created Time: 03/07/2024 09:31:26 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc343/tasks/abc343_e
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

  auto Get3 = [&](int a1, int b1, int c1, int a2, int b2, int c2, int a3, int b3, int c3) -> int {
    int ans = 1;
    ans *= max(0, min({a1, a2, a3}) + 7 - max({a1, a2, a3}));
    ans *= max(0, min({b1, b2, b3}) + 7 - max({b1, b2, b3}));
    ans *= max(0, min({c1, c2, c3}) + 7 - max({c1, c2, c3}));
    return ans;
  };
  auto Get2 = [&](int a1, int b1, int c1, int a2, int b2, int c2) -> int {
    int ans = 1;
    ans *= max(0, (min(a1, a2) + 7 - max(a1, a2)));
    ans *= max(0, (min(b1, b2) + 7 - max(b1, b2)));
    ans *= max(0, (min(c1, c2) + 7 - max(c1, c2)));
    return ans;
  };
  int v1, v2, v3;
  cin >> v1 >> v2 >> v3;
  for (int x1 = -8; x1 <= 8; x1++) {
    for (int y1 = -8; y1 <= 8; y1++) {
      for (int z1 = -8; z1 <= 8; z1++) {
        for (int x2 = -8; x2 <= 8; x2++) {
          for (int y2 = -8; y2 <= 8; y2++) {
            for (int z2 = -8; z2 <= 8; z2++) {
              int z = Get3(0, 0, 0, x1, y1, z1, x2, y2, z2);
              int y = Get2(0, 0, 0, x1, y1, z1) + Get2(0, 0, 0, x2, y2, z2) + Get2(x1, y1, z1, x2, y2, z2) - 3 * z;
              int x = 3 * 7 * 7 * 7 - 2 * y - 3 * z;
              if (x == v1 && y == v2 && z == v3) {
                cout << "Yes\n0 0 0 " << x1 << ' ' << y1 << ' ' << z1 << ' ' << x2 << ' ' << y2 << ' ' << z2 << '\n';
                return 0;
              }
            }
          }
        }
      }
    }
  }
  cout << "No\n";
  return 0;
}
