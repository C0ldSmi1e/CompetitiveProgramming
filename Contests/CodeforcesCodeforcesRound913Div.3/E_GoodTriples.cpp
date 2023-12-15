/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-05 08:08:32
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1907/problem/E
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

const int N = 1e7 + 10;
long long dp[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  vector<int> dp(10);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        if (i + j + k < 10) {
          dp[i + j + k] += 1;
        }
      }
    }
  }
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    long long res = 1;
    while (n > 0) {
      res *= dp[n % 10];
      n /= 10;
    }
    cout << res << '\n';
  }
  return 0;
}
