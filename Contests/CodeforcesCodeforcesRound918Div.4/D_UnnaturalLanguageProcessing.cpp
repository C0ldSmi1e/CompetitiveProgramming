/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-28 06:44:58
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1915/problem/D
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
    string s;
    cin >> s;
    vector<bool> dp(n + 1);
    dp[0] = true;
    set<char> C{'b', 'c', 'd'};
    set<char> V{'a', 'e'};
    for (int i = 0; i < n; i++) {
      if (dp[i]) {
        if (i + 1 < n && C.count(s[i]) && V.count(s[i + 1])) {
          dp[i + 2] = true;
        }
        if (i + 2 < n && C.count(s[i]) && V.count(s[i + 1]) && C.count(s[i + 2])) {
          dp[i + 3] = true;
        }
      }
    }
    assert(dp[n] == true);
    vector<string> g;
    auto Dfs = [&](auto& self, int i) -> void {
      if (i == 0) {
        return;
      }
      if (dp[i - 2] && C.count(s[i - 2]) && V.count(s[i - 1])) {
        g.emplace_back(s.substr(i - 2, 2));
        self(self, i - 2);
      } else if (dp[i - 3] && C.count(s[i - 3]) && V.count(s[i - 2]) && C.count(s[i - 1])) {
        g.emplace_back(s.substr(i - 3, 3));
        self(self, i - 3);
      }
    };
    Dfs(Dfs, n);
    reverse(g.begin(), g.end());
    for (int i = 0; i < (int) g.size(); i++) {
      cout << g[i] << ".\n"[i == (int) g.size() - 1];
    }
  }
  return 0;
}
