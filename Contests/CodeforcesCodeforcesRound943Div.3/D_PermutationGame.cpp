/**
 * Author: C0ldSmi1e
 * Created Time: 05/02/2024 08:01:11 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1968/problem/D
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
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    --x;
    --y;
    vector<int> p(n);
    for (auto& u : p) {
      cin >> u;
      --u;
    }
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    auto Get = [&](int x) -> vector<long long> {
      vector<long long> dp(n);
      vector<long long> sum(n);
      vector<int> mx(n);
      vector<int> dist(n, -1);
      mx[x] = a[x];
      sum[x] = a[x];
      dp[x] = 1ll * a[x] * k;
      dist[x] = 0;
      while (true) {
        int y = x;
        x = p[x];
        if (dist[x] != -1) {
          break;
        }
        dist[x] = dist[y] + 1;
        if (dist[x] >= k) {
          break;
        }
        sum[x] = sum[y] + a[x];
        mx[x] = max(mx[y], a[x]);
        dp[x] = sum[x] + 1ll * (k - dist[x] - 1) * mx[x];
      }
      return dp;
    };
    auto dp1 = Get(x);
    auto dp2 = Get(y);
    debug(dp1);
    debug(dp2);
    long long ans1 = *max_element(dp1.begin(), dp1.end());
    long long ans2 = *max_element(dp2.begin(), dp2.end());
    if (ans1 == ans2) {
      cout << "Draw\n";
      continue;
    }
    if (ans1 > ans2) {
      cout << "Bodya\n";
      continue;
    }
    cout << "Sasha\n";
  }
  return 0;
}
