/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-19 06:54:43
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1914/problem/D
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

  auto Get = [&](vector<int>& a) -> pair<vector<int>, vector<int>> {
    int n = (int) a.size();
    vector<int> l(n);
    l[0] = a[0];
    for (int i = 1; i < n; i++) {
      l[i] = max(l[i - 1], a[i]);
    }
    vector<int> r(n);
    r[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      r[i] = max(r[i + 1], a[i]);
    }
    return make_pair(l, r);
  };
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    vector<int> b(n);
    for (auto& u : b) {
      cin >> u;
    }
    vector<int> c(n);
    for (auto& u : c) {
      cin >> u;
    }
    auto [al, ar] = Get(a);
    auto [bl, br] = Get(b);
    auto [cl, cr] = Get(c);
    int res = 0;
    for (int i = 1; i < n - 1; i++) {
      res = max(res, a[i] + bl[i - 1] + cr[i + 1]);
      res = max(res, a[i] + cl[i - 1] + br[i + 1]);
      res = max(res, b[i] + al[i - 1] + cr[i + 1]);
      res = max(res, b[i] + cl[i - 1] + ar[i + 1]);
      res = max(res, c[i] + al[i - 1] + br[i + 1]);
      res = max(res, c[i] + bl[i - 1] + ar[i + 1]);
    }
    cout << res << '\n';
  }
  return 0;
}
