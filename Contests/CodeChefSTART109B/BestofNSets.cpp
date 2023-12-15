/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-22 06:34:00
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START109B/problems/BESTOFTENNIS
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
    cout << max(x, y) - 1 + max(x, y) << '\n';
  }
  return 0;
}
