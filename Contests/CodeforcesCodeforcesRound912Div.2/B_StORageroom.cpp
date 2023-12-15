/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-30 08:44:03
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1903/problem/B
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
    vector<vector<int>> g(n, vector<int>(n));
    for (auto& u : g) {
      for (auto& v : u) {
        cin >> v;
      }
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      for (int bit = 0; bit < 30; bit++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
          cnt += ((g[i][j] >> bit) & 1);
        }
        if (cnt == n - 1) {
          a[i] |= (1 << bit);
        }
      }
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i != j) {
          flag &= (g[i][j] == (a[i] | a[j]));
        }
      }
    }
    if (flag) {
      cout << "YES\n";
      for (auto& u : a) {
        cout << u << ' ';
      }
      cout << '\n';
      continue;
    }
    cout << "NO\n";
  }
  return 0;
}
