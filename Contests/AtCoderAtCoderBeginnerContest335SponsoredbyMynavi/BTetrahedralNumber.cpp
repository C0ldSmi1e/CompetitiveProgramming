/**
 * Author: C0ldSmi1e
 * Created Time: 01/07/2024 11:26:49 AM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc335/tasks/abc335_b
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

  int n;
  cin >> n;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        if (i + j + k <= n) {
          cout << i << ' ' << j << ' ' << k << '\n';
        }
      }
    }
  }
  return 0;
}
