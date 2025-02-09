/**
 * Author: C0ldSmi1e
 * Created Time: 09/01/2024 10:12:58 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/2008/problem/A
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
    int x, y;
    cin >> x >> y;
    y %= 2;
    if (x & 1) {
      cout << "NO\n";
      continue;
    }
    if (y == 0) {
      cout << "YES\n";
      continue;
    }
    cout << (x >= 2 ? "YES\n" : "NO\n");
  }
  return 0;
}
