/**
 * Author: C0ldSmi1e
 * Created Time: 01/16/2024 10:23:24 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1921/problem/G
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
    vector<string> g(n);
    for (auto& s : g) {
      cin >> s;
    }
    auto Get = [&]() -> int {
      vector<vector<int>> pref1(n, vector<int>(m));
      vector<vector<int>> pref2(n, vector<int>(m));
      vector<vector<int>> sum(n, vector<int>(m));
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          pref1[i][j] = (int) (g[i][j] == '#');
          pref2[i][j] = (int) (g[i][j] == '#');
          if (i > 0) {
            pref1[i][j] += pref1[i - 1][j];
          }
          if (i > 0 && j + 1 < m) {
            pref2[i][j] += pref2[i - 1][j + 1];
          }
        }
      }
      int mx = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (j > 0) {
            sum[i][j] = sum[i][j - 1];
          }
          sum[i][j] += pref1[i][j];
          if (i >= k + 1) {
            sum[i][j] -= pref1[i - (k + 1)][j];
          }
          if (j >= k + 1) {
            sum[i][j] -= pref2[i][j - (k + 1)];
          } else {
            int ii = j - (k + 1) + i;
            if (ii >= 0) {
              sum[i][j] -= pref2[ii][0];
            }
          }
          if (i >= k + 1) {
            sum[i][j] += pref2[i - (k + 1)][j];
          }
          mx = max(mx, sum[i][j]);
        }
      }
      return mx;
    };
    int res = Get();
    reverse(g.begin(), g.end());
    res = max(res, Get());
    for (auto& s : g) {
      reverse(s.begin(), s.end());
    }
    res = max(res, Get());
    reverse(g.begin(), g.end());
    res = max(res, Get());
    cout << res << '\n';
  }
  return 0;
}
