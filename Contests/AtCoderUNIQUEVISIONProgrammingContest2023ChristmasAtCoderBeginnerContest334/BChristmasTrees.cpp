/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-26 16:33:12
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc334/tasks/abc334_b
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

  long long a, m, l, r;
  cin >> a >> m >> l >> r;
  long long x = 0;
  if (a <= l) {
    x = l + (m - (l - a) % m) % m;
  } else {
    x = l + (a - l) % m;
  }
  cout << max(0ll, r - x + 1 + m - 1) / m << '\n';
  return 0;
}
