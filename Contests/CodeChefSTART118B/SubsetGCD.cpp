/**
 * Author: C0ldSmi1e
 * Created Time: 01/24/2024 06:32:11 AM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START118B/problems/GCDPERM
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
    int g = n / k;
    for (int i = 1; i <= n; i++) {
      if (i % g == 0) {
        cout << i << ' ';
        if (--k == 0) {
          break;
        }
      }
    }
    cout << '\n';
  }
  return 0;
}
