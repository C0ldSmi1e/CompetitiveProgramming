/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-26 10:31:46
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc330/tasks/abc330_a
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

  int n, m;
  cin >> n >> m;
  int res = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    res += (int) (x >= m);
  }
  cout << res << '\n';
  return 0;
}
