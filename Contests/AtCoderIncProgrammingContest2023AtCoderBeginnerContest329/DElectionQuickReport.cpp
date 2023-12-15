/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-18 22:41:29
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc329/tasks/abc329_d
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

  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (auto& u : a) {
    cin >> u;
    --u;
  }
  int res = -1;
  int mx = 0;
  vector<int> cnt(n);
  for (int i = 0; i < m; i++) {
    cnt[a[i]] += 1;
    if (cnt[a[i]] > mx) {
      mx = cnt[a[i]];
      res = a[i];
    } else if (cnt[a[i]] == mx && res > a[i]) {
      res = a[i];
    }
    cout << res + 1 << '\n';
  }
  return 0;
}
