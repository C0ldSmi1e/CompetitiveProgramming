/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-09 09:26:25
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1904/problem/D1
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
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
      --u;
    }
    vector<int> b(n);
    vector<vector<int>> idx(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      --b[i];
      idx[b[i]].emplace_back(i);
    }
    bool flag = true;
    for (int x = 0; x < n; x++) {
      for (auto& i : idx[x]) {
        int l = i;
        bool ok_l = true;
        while (l >= 0 && a[l] != x) {
          if (b[l] < x || a[l] > x) {
            ok_l = false;
          }
          l -= 1;
        }
        ok_l &= (l >= 0 && a[l] == x);
        int r = i;
        bool ok_r = true;
        while (r < n && a[r] != x) {
          if (b[r] < x || a[r] > x) {
            ok_r = false;
          }
          r += 1;
        }
        ok_r &= (r < n && a[r] == x);
        flag &= (ok_l || ok_r);
      }
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
