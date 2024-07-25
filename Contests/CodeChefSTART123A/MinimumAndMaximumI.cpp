/**
 * Author: C0ldSmi1e
 * Created Time: 02/28/2024 06:30:30 AM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START123A/problems/MINANDMAX
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
    long long ans = 2ll * (1ll + n / 2) * (n / 2) / 2ll;
    if (n & 1) {
      ans += (n + 1) / 2;
    }
    cout << ans << '\n';
  }
  return 0;
}
