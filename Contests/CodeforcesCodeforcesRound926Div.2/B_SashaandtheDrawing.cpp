/**
 * Author: C0ldSmi1e
 * Created Time: 02/15/2024 06:42:21 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1929/problem/B
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
    int n, k;
    cin >> n >> k;
    if (k == 4 * n - 2) {
      cout << 2 * n << '\n';
      continue;
    }
    if (k == 4 * n - 1) {
      cout << 2 * n - 1 << '\n';
      continue;
    }
    cout << (k + 1) / 2 << '\n';
  }
  return 0;
}
