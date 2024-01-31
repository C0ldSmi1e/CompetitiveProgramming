/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-20 07:09:24
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START113B/problems/MINIMISEMAX
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
    if (x == 0) {
      cout << "-2\n";
      continue;
    }
    if (y >= x - 1) {
      cout << "1\n";
      continue;
    }
    if (x > 2 * (y + 1)) {
      cout << x - 2 * y << '\n';
      continue;
    }
    cout << "2\n";
  }
  return 0;
}
