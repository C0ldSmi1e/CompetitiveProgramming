/**
 * Author: C0ldSmi1e
 * Created Time: 03/02/2025 06:51:24 PM
**/

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
    int x, y;
    cin >> x >> y;
    int ans = 0;
    int cnt = (y + 1) / 2;
    int empty = cnt * 3 * 5 - y * 4;
    ans = cnt;
    if (empty < x) {
      x -= empty;
      ans += (x + 14) / 15;
    }
    cout << ans << '\n';
  }
  return 0;
}
