/**
 * Author: C0ldSmi1e
 * Created Time: 04/19/2025 09:39:19 PM
**/

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
    int n, s, m;
    cin >> n >> s >> m;
    vector<pair<int, int>> a(n);
    for (auto& [x, y] : a) {
      cin >> x >> y;
    }
    bool flag = false;
    for (int i = 1; i < n; i++) {
      flag |= a[i].first - a[i - 1].second >= s;
    }
    flag |= a[0].first >= s;
    flag |= m - a.back().second >= s;
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
