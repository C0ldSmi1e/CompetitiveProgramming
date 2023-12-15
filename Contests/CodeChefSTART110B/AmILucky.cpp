/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-29 06:38:06
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START110B/problems/SPCP4
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
    int n, x, k;
    cin >> n >> x >> k;
    int y = n - x;
    x %= k;
    y %= k;
    cout << abs(x - y) << '\n';
  }
  return 0;
}
