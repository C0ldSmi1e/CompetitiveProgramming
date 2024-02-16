/**
 * Author: C0ldSmi1e
 * Created Time: 02/14/2024 06:33:00 AM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START121A/problems/CAESARLITE
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
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < n; i++) {
      int x = (int) (t[i] - s[i]);
      while (!(x >= 0 && x % 3 == 0)) {
        x += 26;
      }
      cout << x / 3 << " \n"[i == n - 1];
    }
  }
  return 0;
}
