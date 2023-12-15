/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-29 06:32:17
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START110B/problems/SPCP3
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
    int a, b;
    cin >> a >> b;
    int res = (int) 1e9;
    for (int i = 0; i < b; i++) {
      if ((a + i) % (b - i) == 0) {
        res = min(res, i);
      }
    }
    for (int i = 0; i < a; i++) {
      if ((a - i) % (b + i) == 0) {
        res = min(res, i);
      }
    }
    cout << res << '\n';
  }
  return 0;
}
