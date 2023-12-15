/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-09 08:13:26
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1904/problem/A
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
    int a, b;
    cin >> a >> b;
    int x1, y1;
    cin >> x1 >> y1;
    int x2, y2;
    cin >> x2 >> y2;
    set<pair<int, int>> pos{{x1 + b, y1 + a}, {x1 + b, y1 - a}, {x1 - b, y1 + a}, {x1 - b, y1 - a}, {x1 - a, y1 - b}, {x1 + a, y1 - b}, {x1 + a, y1 + b}, {x1 - a, y1 + b}};
    int res = 0;
    for (auto& [x, y] : pos) {
      debug(x, y);
      if ((x + b == x2 && y + a == y2) || (x + b == x2 && y - a == y2) || (x - b == x2 && y + a == y2) || (x - b == x2 && y - a == y2) || (x + a == x2 && y + b == y2) || (x + a == x2 && y - b == y2) || (x - a == x2 && y + b == y2) || (x - a == x2 && y - b == y2)) {
        res += 1;
      }
      debug(res);
    }
    cout << res << '\n';
  }
  return 0;
}
