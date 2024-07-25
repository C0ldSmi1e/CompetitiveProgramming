/**
 * Author: C0ldSmi1e
 * Created Time: 02/26/2024 09:42:01 PM
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1932/problem/F
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
    vector<vector<vector<int>>> p(n + 1, vector<vector<int>>(2));
    for (int i = 0; i < m; i++) {
      int l, r;
      cin >> l >> r;
      p[l][0].emplace_back(l);
      p[r][1].emplace_back(l);
    }
    vector<int> dp(n + 1);
    multiset<int> S;
    for (int i = 1; i <= n; i++) {
      dp[i] = dp[i - 1];
      for (auto& l : p[i][0]) {
        S.insert(l);
      }
      if ((int) S.size() > 0) {
        int mn = *S.begin();
        dp[i] = max(dp[i], dp[mn - 1] + (int) S.size());
      }
      for (auto& l : p[i][1]) {
        S.erase(S.find(l));
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
  return 0;
}
