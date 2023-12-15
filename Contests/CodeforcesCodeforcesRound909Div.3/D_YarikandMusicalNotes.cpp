/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-17 07:12:09
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1899/problem/D
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    map<int, int> mp;
    long long res = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      res += mp[x];
      mp[x] += 1;
    }
    res += 1ll * mp[2] * mp[1];
    cout << res << '\n';
  }
  return 0;
}
