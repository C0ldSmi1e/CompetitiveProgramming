/**
 * Author: C0ldSmi1e
 * Created Time: 01/14/2024 11:43:37 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1917/problem/F
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
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    sort(a.rbegin(), a.rend());
    if (d < a[0] + a[1]) {
      cout << "NO\n";
      continue;
    }
    const int N = 2010;
    vector<bitset<N>> dp(d + 1);
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
      for (int j = d; j >= 0; j--) {
        dp[j] |= (dp[j] << a[i]);
        if (j - a[i] >= 0) {
          dp[j] |= dp[j - a[i]];
        }
      }
    }
    bool flag = dp[0][d - a[0]];
    for (int x = a[0]; x <= d - a[0]; x++) {
      if (dp[x][d - x]) {
        flag = true;
        break;
      }
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
