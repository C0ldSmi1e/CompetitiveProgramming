/**
 * Author: C0ldSmi1e
 * Created Time: 06/09/2024 03:32:00 PM
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1980/problem/E
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto& u : a) {
      for (auto& v : u) {
        cin >> v;
      }
    }
    vector<vector<int>> b(n, vector<int>(m));
    for (auto& u : b) {
      for (auto& v : u) {
        cin >> v;
      }
    }
    bool flag = true;
    {
      set<vector<int>> S;
      for (int i = 0; i < n; i++) {
        vector<int> c(m);
        for (int j = 0; j < m; j++) {
          c[j] = a[i][j];
        }
        sort(c.begin(), c.end());
        S.insert(c);
      }
      for (int i = 0; i < n; i++) {
        vector<int> c(m);
        for (int j = 0; j < m; j++) {
          c[j] = b[i][j];
        }
        sort(c.begin(), c.end());
        flag &= (S.find(c) != S.end());
      }
    }
    {
      set<vector<int>> S;
      for (int j = 0; j < m; j++) {
        vector<int> c(n);
        for (int i = 0; i < n; i++) {
          c[i] = a[i][j];
        }
        sort(c.begin(), c.end());
        S.insert(c);
      }
      for (int j = 0; j < m; j++) {
        vector<int> c(n);
        for (int i = 0; i < n; i++) {
          c[i] = b[i][j];
        }
        sort(c.begin(), c.end());
        flag &= (S.find(c) != S.end());
      }
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
