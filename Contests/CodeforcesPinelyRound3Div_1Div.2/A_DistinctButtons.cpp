/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-23 06:37:03
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1909/problem/A
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
    bool xp = false;
    bool xn = false;
    bool yp = false;
    bool yn = false;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      xp |= x > 0;
      xn |= x < 0;
      yp |= y > 0;
      yn |= y < 0;
    }
    if ((xp && xn) && (yp && yn)) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
