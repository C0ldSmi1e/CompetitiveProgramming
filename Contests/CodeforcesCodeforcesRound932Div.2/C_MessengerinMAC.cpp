/**
 * Author: C0ldSmi1e
 * Created Time: 03/08/2024 09:08:57 AM
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1935/problem/C
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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (auto& [x, y] : a) {
      cin >> y >> x;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int tot = 0;
      multiset<int> S;
      for (int j = i; j < n; j++) {
        S.insert(a[j].second);
        tot += a[j].second;
        if (a[j].first - a[i].first > m) {
          break;
        }
        while (tot + a[j].first - a[i].first > m) {
          tot -= *prev(S.end());
          S.extract(prev(S.end()));
        }
        ans = max(ans, (int) S.size());
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
