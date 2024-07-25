/**
 * Author: C0ldSmi1e
 * Created Time: 04/08/2024 08:26:54 AM
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1955/problem/E
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
    string s;
    cin >> n >> s;
    for (int len = n; len >= 1; len--) {
      vector<int> pref(n + 1);
      string t = s;
      for (int i = 0; i < n; i++) {
        pref[i + 1] += pref[i];
        pref[i + 1] &= 1;
        t[i] ^= pref[i + 1];
        if (i + len - 1 < n) {
          if (t[i] == '0') {
            t[i] = '1';
            pref[i + 1] += 1;
            if (i + 1 + len <= n) {
              pref[i + 1 + len] -= 1;
            }
          }
        }
      }
      if (count(t.begin(), t.end(), '1') == n) {
        cout << len << '\n';
        break;
      }
    }
  }
  return 0;
}
