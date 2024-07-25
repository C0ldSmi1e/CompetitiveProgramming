/**
 * Author: C0ldSmi1e
 * Created Time: 03/27/2024 08:50:15 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc346/tasks/abc346_e
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

  int n, m, q;
  cin >> n >> m >> q;
  vector<tuple<int, int, int>> a(q);
  for (auto& [t, x, y] : a) {
    cin >> t >> x >> y;
    --x;
  }
  reverse(a.begin(), a.end());
  vector<bool> r(n);
  vector<bool> c(m);
  int rc = 0;
  int cc = 0;
  map<int, long long> mp;
  for (auto& [t, x, y] : a) {
    debug(t, x, y);
    if (t == 1) {
      if (!r[x]) {
        r[x] = true;
        if (m - cc > 0) {
          mp[y] += m - cc;
          rc += 1;
        }
      }
    } else {
      if (!c[x]) {
        c[x] = true;
        if (n - rc > 0) {
          mp[y] += n - rc;
          cc += 1;
        }
      }
    }
  }
  debug(mp);
  long long zeros = 1ll * n * m;
  for (auto& [x, y] : mp) {
    zeros -= y;
  }
  if (zeros > 0) {
    mp[0] += zeros;
  }
  cout << (int) mp.size() << '\n';
  for (auto& [x, y] : mp) {
    cout << x << ' ' << y << '\n';
  }
  return 0;
}
