/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-23 06:54:54
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1909/problem/C
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
    vector<int> l(n);
    for (auto& u : l) {
      cin >> u;
    }
    vector<int> r(n);
    for (auto& u : r) {
      cin >> u;
    }
    vector<int> c(n);
    for (auto& u : c) {
      cin >> u;
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    vector<pair<int, int>> seg;
    vector<int> stk;
    for (int i = 0, j = 0; j < n; j++) {
      while (i < n && l[i] < r[j]) {
        stk.emplace_back(l[i]);
        i += 1;
      }
      assert((int) stk.size() > 0);
      seg.emplace_back(make_pair(stk.back(), r[j]));
      stk.pop_back();
    }
    sort(c.begin(), c.end());
    sort(seg.begin(), seg.end(), [&](auto i, auto j){
      return i.second - i.first > j.second - j.first;
    });
    long long res = 0;
    int j = 0;
    for (auto& [x, y] : seg) {
      res += 1ll * (y - x) * c[j];
      j += 1;
    }
    cout << res << '\n';
  }
  return 0;
}
