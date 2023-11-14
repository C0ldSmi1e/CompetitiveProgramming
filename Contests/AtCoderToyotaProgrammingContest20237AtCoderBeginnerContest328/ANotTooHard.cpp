/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-12 11:27:08
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc328/tasks/abc328_a
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  int n, x;
  cin >> n >> x;
  int res = 0;
  for (int i = 0; i < n; i++) {
    int y;
    cin >> y;
    if (y <= x) {
      res += y;
    }
  }
  cout << res << '\n';
  return 0;
}
