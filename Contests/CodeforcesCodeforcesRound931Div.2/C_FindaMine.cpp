/**
 * Author: C0ldSmi1e
 * Created Time: 03/01/2024 07:04:15 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1934/problem/C
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  auto Ask = [&](int x, int y) -> int {
    cout << "? " << x << ' ' << y << endl;
    cin >> x;
    return x;
  };
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    int d1 = Ask(1, 1);
    int d2 = Ask(n, 1);
    int d3 = Ask(1, m);
    int x1 = d1 + 1 - (d1 + 1 + d2 + 1 - n - 1) / 2;
    int y1 = 1 + (d1 + 1 + d2 + 1 - n - 1) / 2;
    int x2 = 1 + (d1 + 1 + d3 + 1 - m - 1) / 2;
    int y2 = (m - d3) + (d1 + 1 + d3 + 1 - m - 1) / 2;
    if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && Ask(x1, y1) == 0) {
      cout << "! " << x1 << ' ' << y1 << endl;
    } else {
      cout << "! " << x2 << ' ' << y2 << endl;
    }
  }
  return 0;
}

