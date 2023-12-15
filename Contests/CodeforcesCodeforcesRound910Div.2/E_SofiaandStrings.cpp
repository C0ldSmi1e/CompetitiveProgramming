/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-20 22:25:41
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1898/problem/E
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
    string s, t;
    cin >> s >> t;
    vector<vector<int>> idx(26);
    for (int i = n - 1; i >= 0; i--) {
      idx[(int) (s[i] - 'a')].emplace_back(i);
    }
    vector<int> mx(26, -1);
    bool flag = true;
    for (int i = 0; i < m; i++) {
      int c = (int) (t[i] - 'a');
      bool ok = false;
      while (!ok && (int) idx[c].size() > 0) {
        bool valid = true;
        for (int cc = c + 1; cc < 26; cc++) {
          valid &= mx[cc] < idx[c].back();
        }
        if (valid) {
          mx[c] = idx[c].back();
          ok = true;
        }
        idx[c].pop_back();
      }
      if (!ok) {
        flag = false;
        break;
      }
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
