/**
 * Author: C0ldSmi1e
 * Created Time: 01/26/2026 09:57:55 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/2185/problem/D
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
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    vector<pair<int, int>> ops(m);
    for (auto& [x, y] : ops) {
      cin >> x >> y;
      --x;
    }
    auto c = a;
    vector<int> b(n);
    int cnt = 0;
    for (auto& [x, y] : ops) {
      if (b[x] != cnt) {
        b[x] = cnt;
        c[x] = a[x];
      }
      c[x] += y;
      if (c[x] > h) {
        cnt += 1;
        b[x] = cnt;
        c[x] = a[x];
      }
    }
    for (int i = 0; i < n; i++) {
      if (b[i] != cnt) {
        c[i] = a[i];
      }
    }
    for (auto& u : c) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
