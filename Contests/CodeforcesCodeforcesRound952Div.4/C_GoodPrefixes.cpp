/**
 * Author: C0ldSmi1e
 * Created Time: 06/11/2024 08:20:02 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1985/problem/C
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
    int mx = 0;
    long long sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x > mx) {
        sum += mx;
        mx = x;
      } else {
        sum += x;
      }
      ans += (int) (mx == sum);
    }
    cout << ans << '\n';
  }
  return 0;
}
