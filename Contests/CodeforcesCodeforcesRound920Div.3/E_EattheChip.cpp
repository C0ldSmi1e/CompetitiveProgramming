/**
 * Author: C0ldSmi1e
 * Created Time: 01/15/2024 07:17:05 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1921/problem/E
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
    int n, m, x1, x2, y1, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    if (x1 >= x2) {
      cout << "Draw\n";
      continue;
    }
    int dx = x2 - x1;
    int dy = abs(y1 - y2);
    if (dx & 1) {
      // A or D
      int ca = (dx + 1) / 2;
      int cb = dx - ca;
      int space;
      if (y1 <= y2) {
        space = m - y2;
      } else {
        space = y2 - 1;
      }
      space = min(space, cb);
      if (ca - space >= dy) {
        cout << "Alice\n";
      } else {
        cout << "Draw\n";
      }
    } else {
      // B or D
      int cb = dx / 2;
      int ca = dx - cb;
      int space;
      if (y1 <= y2) {
        space = y1 - 1;
      } else {
        space = m - y1;
      }
      space = min(space, ca);
      debug(ca, cb, space, dy);
      if (cb - space >= dy) {
        cout << "Bob\n";
      } else {
        cout << "Draw\n";
      }
    }
  }
  return 0;
}
