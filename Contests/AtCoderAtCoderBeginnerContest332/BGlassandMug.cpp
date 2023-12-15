/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-11 14:39:28
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc332/tasks/abc332_b
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

  int k, g, m;
  cin >> k >> g >> m;
  int G = 0, M = 0;
  while (k--) {
    if (G == g) {
      G = 0;
      continue;
    }
    if (M == 0) {
      M = m;
      continue;
    }
    int have = M;
    int need = g - G;
    int take = min(have, need);
    G += take;
    M -= take;
  }
  cout << G << ' ' << M << '\n';
  return 0;
}
