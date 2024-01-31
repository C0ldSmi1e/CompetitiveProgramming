/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-28 06:36:26
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1915/problem/A
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
    int x, y, z;
    cin >> x >> y >> z;
    if (x == y) {
      cout << z << '\n';
    }
    if (x == z) {
      cout << y << '\n';
    }
    if (y == z) {
      cout << x << '\n';
    }
  }
  return 0;
}
