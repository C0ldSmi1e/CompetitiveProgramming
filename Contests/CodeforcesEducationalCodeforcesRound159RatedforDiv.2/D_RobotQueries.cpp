/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-03 10:55:20
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1902/problem/D
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

  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<pair<int, int>> pos(n + 1);
  for (int i = 0; i < n; i++) {
    auto [x, y] = pos[i];
    if (s[i] == 'L') {
      x -= 1;
    }
    if (s[i] == 'R') {
      x += 1;
    }
    if (s[i] == 'U') {
      y += 1;
    }
    if (s[i] == 'D') {
      y -= 1;
    }
    pos[i + 1] = make_pair(x, y);
  }
  map<pair<int, int>, vector<int>> mp;
  for (int i = 0; i <= n; i++) {
    mp[pos[i]].emplace_back(i);
  }
  auto Check = [&](int l, int r, pair<int, int> p) -> bool {
    // Check if p is in [l, r]
    auto it = lower_bound(mp[p].begin(), mp[p].end(), l);
    return it != mp[p].end() && *it <= r;
  };
  while (q--) {
    int x, y, l, r;
    cin >> x >> y >> l >> r;
    --l;
    bool flag = false;
    flag |= Check(0, l, make_pair(x, y));
    flag |= Check(l, r, make_pair(pos[r].first + pos[l].first - x, pos[r].second + pos[l].second - y));
    flag |= Check(r, n, make_pair(x, y));
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
