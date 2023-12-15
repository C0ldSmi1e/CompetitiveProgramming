/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-26 10:43:52
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc330/tasks/abc330_b
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

  int n, l, r;
  cin >> n >> l >> r;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x >= l && x <= r) {
      cout << x << ' ';
    } else if (x < l) {
      cout << l << ' ';
    } else {
      cout << r << ' ';
    }
  }
  cout << '\n';
  return 0;
}
