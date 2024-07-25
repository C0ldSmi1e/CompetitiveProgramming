/**
 * Author: C0ldSmi1e
 * Created Time: 02/26/2024 11:44:03 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1932/problem/A
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
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '*' || dp[i] == -1) {
        continue;
      }
      dp[i + 1] = max(dp[i + 1], dp[i] + (int) (s[i] == '@'));
      if (i + 2 <= n) {
        dp[i + 2] = max(dp[i + 2], dp[i] + (int) (s[i] == '@'));
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
  return 0;
}
