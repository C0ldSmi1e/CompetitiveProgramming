/**
 * Author: C0ldSmi1e
 * Created Time: 06/23/2024 08:06:35 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1986/problem/D
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
    long long ans = -1;
    for (int i = 0; i < n - 1; i++) {
      vector<int> a;
      for (int j = 0; j < n; j++) {
        a.emplace_back((int) (s[j] - '0'));
        if (i == j) {
          j += 1;
          a.back() = a.back() * 10 + (int) (s[j] - '0');
        }
      }
      __int128 res = 0;
      if (n - 1 == 1) {
        res = a[0];
      } else if (*min_element(a.begin(), a.end()) == 0) {
        res = 0;
      } else if (*max_element(a.begin(), a.end()) == 1) {
        res = 1;
      } else {
        for (auto& u : a) {
          if (u > 1) {
            res += u;
          }
        }
      }
      if (ans == -1 || res < ans) {
        ans = res;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
