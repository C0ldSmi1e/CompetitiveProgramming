/**
 * Author: C0ldSmi1e
 * Created Time: 02/13/2024 06:52:48 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1931/problem/D
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
    int n, x, y;
    cin >> n >> x >> y;
    map<pair<int, int>, int> mp;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      ans += mp[{(x - a % x) % x, a % y}];
      mp[{a % x, a % y}] += 1;
    }
    cout << ans << '\n';
  }
  return 0;
}
