/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-05 07:07:42
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1907/problem/A
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
    string s;
    cin >> s;
    for (char x = '1'; x <= '8'; x++) {
      if (x == s[1]) {
        continue;
      }
      cout << s[0] << x << '\n';
    }
    for (char c = 'a'; c <= 'h'; c++) {
      if (c == s[0]) {
        continue;
      }
      cout << c << s[1] << '\n';
    }
  }
  return 0;
}
