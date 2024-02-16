/**
 * Author: C0ldSmi1e
 * Created Time: 02/15/2024 06:51:42 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1929/problem/C
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
    long long k, x, a;
    cin >> k >> x >> a;
    long long lost = 1;
    for (int i = 0; i < x; i++) {
      lost += lost / (k - 1) + 1;
      if (lost > a) {
        break;
      }
    }
    cout << (lost <= a ? "YES\n" : "NO\n");
  }
  return 0;
}
