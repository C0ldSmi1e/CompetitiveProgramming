/**
 * Author: C0ldSmi1e
 * Created Time: 02/06/2024 07:44:07 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1927/problem/C
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<bool> st(k);
    vector<bool> sa(k);
    vector<bool> sb(k);
    int ca = 0, cb = 0;
    for (auto& u : a) {
      cin >> u;
      --u;
      if (u < k && !sa[u]) {
        ca += 1;
        sa[u] = st[u] = true;
      }
    }
    vector<int> b(m);
    for (auto& u : b) {
      cin >> u;
      --u;
      if (u < k && !sb[u]) {
        cb += 1;
        sb[u] = st[u] = true;
      }
    }
    debug(ca, cb);
    debug(st);
    bool flag = (ca >= k / 2 && cb >= k / 2);
    for (int i = 0; i < k; i++) {
      if (!st[i]) {
        flag = false;
      }
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
