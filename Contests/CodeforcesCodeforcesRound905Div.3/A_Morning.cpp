/**
 * Author: C0ldSmi1e
 * Created Time: 2023-10-24 00:55:15
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1883/problem/A
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int cur = 1;
    int res = 0;
    for (int i = 0; i < 4; i++) {
      int x = (s[i] == '0' ? 10 : (int) (s[i] - '0'));
      int d = abs(cur - x);
      cur = x;
      res += d + 1;
    }
    cout << res << '\n';
  }
  return 0;
}
