/**
 * Author: C0ldSmi1e
 * Created Time: 02/28/2024 06:39:12 AM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START123A/problems/MINANDMAX2
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
    long long ans = (2ll + n) * (n - 1) / 2ll;
    ans += n;
    cout << ans << '\n';
  }
  return 0;
}
