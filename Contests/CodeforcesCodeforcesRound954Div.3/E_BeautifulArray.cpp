/**
 * Author: C0ldSmi1e
 * Created Time: 06/23/2024 08:47:04 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1986/problem/E
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, vector<int>> mp;
    for (auto& u : a) {
      cin >> u;
      mp[u % k].emplace_back(u);
    }
    long long res = 0;
    if (n % 2 == 0) {
      for (auto& [x, y] : mp) {
        sort(y.begin(), y.end());
        if ((int) y.size() & 1) {
          res = -1;
          break;
        }
        for (int i = 0; i < (int) y.size(); i += 2) {
          res += (y[i + 1] - y[i]) / k;
        }
      }
    } else {
      bool odd = false;
      for (auto& [x, y] : mp) {
        sort(y.begin(), y.end());
        debug(y);
        if ((int) y.size() & 1) {
          if (odd) {
            res = -1;
            break;
          }
          odd = true;
          int m = (int) y.size();
          vector<long long> pref(m + 1);
          for (int i = 2; i <= m; i += 2) {
            pref[i] = pref[i - 2] + y[i - 1] - y[i - 2];
          }
          vector<long long> suff(m + 2);
          for (int i = m - 1; i >= 1; i -= 2) {
            suff[i] = suff[i + 2] + y[i] - y[i - 1];
          }
          long long sum = (long long) 8e18;
          for (int i = 1; i <= m; i += 2) {
            long long cur = 0;
            cur += pref[i - 1];
            cur += suff[i + 1];
            sum = min(sum, cur);
          }
          res += sum / k;
        } else {
          for (int i = 0; i < (int) y.size(); i += 2) {
            res += (y[i + 1] - y[i]) / k;
          }
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}
