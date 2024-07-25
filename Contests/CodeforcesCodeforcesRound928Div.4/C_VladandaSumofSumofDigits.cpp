/**
 * Author: C0ldSmi1e
 * Created Time: 02/21/2024 11:53:51 AM
**/

// time-limit: 500
// problem-url: https://codeforces.com/contest/1926/problem/C
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

  const int N = 200010;
  vector<int> dp(N);
  for (int i = 1; i < N; i++) {
    dp[i] = dp[i - 1];
    int x = i;
    while (x > 0) {
      dp[i] += x % 10;
      x /= 10;
    }
  }
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << dp[n] << '\n';
  }
  return 0;
}
