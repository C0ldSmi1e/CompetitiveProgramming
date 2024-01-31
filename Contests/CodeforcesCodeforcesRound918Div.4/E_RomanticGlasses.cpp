/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-28 07:35:55
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1915/problem/E
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
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    vector<vector<long long>> pref(2, vector<long long>(n + 1));
    for (int i = 0; i < n; i++) {
      if (i & 1) {
        pref[1][i + 1] = pref[1][i] + a[i];
        pref[0][i + 1] = pref[0][i];
      } else {
        pref[0][i + 1] = pref[0][i] + a[i];
        pref[1][i + 1] = pref[1][i];
      }
    }
    debug(pref[0]);
    debug(pref[1]);
    set<long long> S;
    bool flag = false;
    for (int i = 0; i <= n; i++) {
      long long d = pref[0][i] - pref[1][i];
      flag |= S.count(d);
      S.insert(d);
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
