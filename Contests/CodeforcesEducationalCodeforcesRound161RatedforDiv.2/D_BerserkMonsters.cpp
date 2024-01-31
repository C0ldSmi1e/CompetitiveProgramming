/**
 * Author: C0ldSmi1e
 * Created Time: 01/18/2024 07:19:47 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1922/problem/D
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
    vector<long long> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    vector<long long> d(n);
    for (auto& u : d) {
      cin >> u;
    }
    vector<int> cand;
    for (int i = 0; i < n; i++) {
      cand.emplace_back(i);
    }
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
      l[i] = i - 1;
      r[i] = i + 1;
    }
    r[n - 1] = -1;
    vector<int> st(n, -1);
    for (int i = 0; i < n; i++) {
      vector<int> die;
      for (auto& u : cand) {
        long long tot = 0;
        if (l[u] != -1) {
          tot += a[l[u]];
        }
        if (r[u] != -1) {
          tot += a[r[u]];
        }
        if (tot > d[u]) {
          die.emplace_back(u);
        }
      }
      cout << (int) die.size() << " \n"[i == n - 1];
      for (auto& u : die) {
        st[u] = i;
      }
      cand.clear();
      for (auto& u : die) {
        if (l[u] != -1) {
          r[l[u]] = r[u];
          if (st[l[u]] < i) {
            cand.emplace_back(l[u]);
            st[l[u]] = i;
          }
        }
        if (r[u] != -1) {
          l[r[u]] = l[u];
          if (st[r[u]] < i) {
            cand.emplace_back(r[u]);
            st[r[u]] = i;
          }
        }
      }
    }
  }
  return 0;
}
