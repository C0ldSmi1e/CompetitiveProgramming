/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-03 07:51:47
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1895/problem/C
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  auto Get = [&](string s) -> int {
    int res = 0;
    for (auto& c : s) {
      res += (int) (c - '0');
    }
    return res;
  };
  int n;
  cin >> n;
  vector<vector<string>> g(6);
  vector<map<int, int>> mp(6);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    g[(int) s.size()].emplace_back(s);
    mp[(int) s.size()][Get(s)] += 1;
  }
  long long res = 0;
  for (int m = 1; m <= 5; m++) {
    for (auto& s : g[m]) {
      res += mp[m][Get(s)];
      for (int mid = 2; mid < m; mid += 2) {
        {
          // prefix:
          // [0, m - mid - 1], [m - mid, [m - 1]]
          // a = [0, m - mid / 2 - 1], b = [m - mid / 2, m - 1]
          // c = a - b, c_len = m - mid
          int a = Get(s.substr(0, m - mid / 2));
          int b = Get(s.substr(m - mid / 2));
          int c = a - b;
          int c_len = m - mid;
          res += mp[c_len][c];
        }
        {
          // suffix:
          // [0, mid - 1], [mid, m - 1]
          // b[0, mid / 2 - 1], a = [mid / 2, m - 1]
          // c = a - b, c_len = m - mid
          int b = Get(s.substr(0, mid / 2));
          int a = Get(s.substr(mid / 2));
          int c = a - b;
          int c_len = m - mid;
          res += mp[c_len][c];
        }
      }
    }
  }
  cout << res << '\n';
  return 0;
}
