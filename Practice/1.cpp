/**
 * Author: C0ldSmi1e
 * Created Time: 04/22/2025 10:12:20 PM
**/

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

  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& u : a) {
    cin >> u;
  }
  vector<int> cnt(n);
  for (int i = 0; i < n; i++) {
    cnt[i] = (int) (a[i] == 0);
    if (i - 1 >= 0) {
      cnt[i] += cnt[i - 1];
    }
  }
  vector<int> dp(m + 5);
  vector<int> sum(m + 5);
  auto Add = [&](vector<int>& b, int l, int r, int v) -> void {
    r = min(r, m);
    l = max(l, 0);
    if (l > r) {
      return;
    }
    b[l] += v;
    b[r + 1] -= v;
  };
  for (int i = 0; i < n; i++) {
    auto ndp = dp;
    if (a[i] == 0) {
      for (int j = 1; j <= m; j++) {
        sum[j] += sum[j - 1];
      }
      for (int j = 0; j <= m; j++) {
        dp[j] += sum[j];
      }
      sum = vector<int>(m + 5, 0);
      for (int j = 0; j <= m; j++) {
        ndp[j] = dp[j];
        if (j - 1 >= 0) {
          ndp[j] = max(ndp[j], ndp[j - 1]);
        }
      }
    }
    if (a[i] > 0) {
      Add(sum, a[i], cnt[i], 1);
    }
    if (a[i] < 0) {
      Add(sum, 0, cnt[i] + a[i], 1);
    }
    swap(dp, ndp);
  }
  for (int j = 1; j <= m; j++) {
    sum[j] += sum[j - 1];
  }
  for (int j = 0; j <= m; j++) {
    dp[j] += sum[j];
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
  return 0;
}
