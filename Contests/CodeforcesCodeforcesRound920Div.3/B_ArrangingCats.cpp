/**
 * Author: C0ldSmi1e
 * Created Time: 01/15/2024 06:41:58 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1921/problem/B
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
    string s, t;
    cin >> n >> s >> t;
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == t[i]) {
        s[i] = t[i] = 0;
      }
    }
    cout << max(count(s.begin(), s.end(), '0'), count(t.begin(), t.end(), '0')) << '\n';
  }
  return 0;
}
