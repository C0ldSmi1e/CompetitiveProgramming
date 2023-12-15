/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-02 11:02:51
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc331/tasks/abc331_a
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

  int M, D;
  cin >> M >> D;
  int y, m, d;
  cin >> y >> m >> d;
  d += 1;
  if (d > D) {
    d = 1;
    m += 1;
    if (m > M) {
      m = 1;
      y += 1;
    }
  }
  cout << y << ' ' << m << ' ' << d << '\n';
  return 0;
}
