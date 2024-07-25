/**
 * Author: C0ldSmi1e
 * Created Time: 06/11/2024 08:17:29 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1985/problem/B
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
    int ans = 0;
    int mx = 0;
    for (int i = 2; i <= n; i++) {
      int sum = 0;
      int x = i;
      while (x <= n) {
        sum += x;
        x += i;
      }
      if (sum > mx) {
        mx = sum;
        ans = i;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
