/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-09 08:55:57
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1904/problem/C
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
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    if (k >= 3) {
      cout << "0\n";
      continue;
    }
    vector<long long> b;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        b.emplace_back(abs(a[i] - a[j]));
      }
    }
    long long res = *min_element(b.begin(), b.end());
    res = min(res, *min_element(a.begin(), a.end()));
    if (k == 2) {
      set<long long> S{a.begin(), a.end()};
      for (auto& u : b) {
        auto it = S.lower_bound(u);
        if (it != S.begin()) {
          res = min(res, abs(u - *prev(it)));
        }
        if (it != S.end()) {
          res = min(res, abs(u - *it));
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}
