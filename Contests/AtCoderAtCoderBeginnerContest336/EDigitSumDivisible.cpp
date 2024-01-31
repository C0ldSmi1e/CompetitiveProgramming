/**
 * Author: C0ldSmi1e
 * Created Time: 01/14/2024 03:00:07 PM
**/

// time-limit: 10000
// problem-url: https://atcoder.jp/contests/abc336/tasks/abc336_e
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

  long long y;
  cin >> y;
  long long res = 0;
  for (int sum = 1; sum <= 140; sum++) {
    vector<int> nums;
    long long yy = y;
    while (yy > 0) {
      nums.emplace_back(yy % 10);
      yy /= 10;
    }
    reverse(nums.begin(), nums.end());
    int n = (int) nums.size();
    vector<vector<vector<long long>>> dp(2, vector<vector<long long>>(sum + 1, vector<long long>(sum)));
    for (int i = 0; i < n; i++) {
      vector<vector<vector<long long>>> ndp(2, vector<vector<long long>>(sum + 1, vector<long long>(sum)));
      for (int x = 1; x <= (i == 0 ? nums[i] : 9); x++) {
        if (x <= sum) {
          ndp[i == 0 && x == nums[i]][x][x % sum] += 1;
        }
      }
      for (int limit = 0; limit <= 1; limit++) {
        for (int j = 0; j <= sum; j++) {
          for (int r = 0; r < sum; r++) {
            if (dp[limit][j][r] == 0) {
              continue;
            }
            for (int x = 0; x <= (limit ? nums[i] : 9); x++) {
              if (j + x <= sum) {
                ndp[limit && x == nums[i]][j + x][(r * 10 + x) % sum] += dp[limit][j][r];
              }
            }
          }
        }
      }
      swap(dp, ndp);
    }
    res += dp[0][sum][0] + dp[1][sum][0];
  }
  cout << res << '\n';
  return 0;
}
