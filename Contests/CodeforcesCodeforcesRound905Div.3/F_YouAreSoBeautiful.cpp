/**
 * Author: C0ldSmi1e
 * Created Time: 2023-10-25 16:09:50
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1883/problem/F
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
    vector<int> a(n);
    map<int, pair<int, int>> mp;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (!mp.count(a[i])) {
        mp[a[i]] = make_pair(n, -1);
      }
      mp[a[i]].first = min(mp[a[i]].first, i);
      mp[a[i]].second = max(mp[a[i]].second, i);
    }
    debug(mp);
    long long res = 1LL * n * (1 + n) / 2;
    int pref = 0;
    for (int i = 0; i < n; i++) {
      if (mp[a[i]].first != i) {
        pref += 1;
        res -= n - i;
      }
      if (mp[a[i]].second != i) {
        res -= i + 1;
        res += pref;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
