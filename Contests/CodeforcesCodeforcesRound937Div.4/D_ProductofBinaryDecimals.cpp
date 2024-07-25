/**
 * Author: C0ldSmi1e
 * Created Time: 03/28/2024 07:58:38 AM
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1950/problem/D
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

  const int N = 100010;
  vector<int> t;
  auto Dfs = [&](auto& self, int x) -> void {
    if (x > N) {
      return;
    }
    if (x > 0) {
      t.emplace_back(x);
    }
    if (x > 0) {
      self(self, x * 10);
    }
    self(self, x * 10 + 1);
  };
  Dfs(Dfs, 0);
  vector<bool> dp(N);
  dp[1] = true;
  for (int i = 1; i < N; i++) {
    if (!dp[i]) {
      continue;
    }
    for (auto& u : t) {
      if (1ll * i * u < N) {
        dp[i * u] = true;
      }
    }
  }
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << (dp[n] ? "YES\n" : "NO\n");
  }
  return 0;
}
