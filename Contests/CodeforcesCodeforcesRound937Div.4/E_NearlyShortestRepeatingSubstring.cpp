/**
 * Author: C0ldSmi1e
 * Created Time: 03/28/2024 08:12:02 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1950/problem/E
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
    int ans = n;
    auto Check = [&](int len) -> bool {
      bool diff = false;
      for (int i = 0; i < len; i++) {
        string t;
        vector<int> cnt(26);
        for (int j = i; j < n; j += len) {
          t += s[j];
          cnt[(int) (s[j] - 'a')] += 1;
        }
        debug(len, t);
        if (count(t.begin(), t.end(), t[0]) != (int) t.size()) {
          if (diff) {
            return false;
          }
          diff = true;
          int sc = 0;
          int mn = (int) t.size();
          for (int c = 0; c < 26; c++) {
            if (cnt[c] > 0) {
              sc += 1;
              mn = min(mn, cnt[c]);
            }
          }
          if (sc > 2) {
            return false;
          }
          if (mn > 1) {
            return false;
          }
        }
      }
      return true;
    };
    for (int i = 1; i <= n / i; i++) {
      if (n % i == 0) {
        if (Check(i)) {
          ans = min(ans, i);
        }
        if (i * i != n) {
          if (Check(n / i)) {
            ans = min(ans, n / i);
          }
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
