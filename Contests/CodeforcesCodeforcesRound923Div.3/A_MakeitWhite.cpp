/**
 * Author: C0ldSmi1e
 * Created Time: 02/06/2024 07:33:23 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1927/problem/A
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
    int l = 0, r = (int) s.size() - 1;
    while (l < (int) s.size() && s[l] == 'W') {
      l += 1;
    }
    debug(l, r);
    while (r >= 0 && s[r] == 'W') {
      r -= 1;
    }
    debug(l, r);
    if (l > r) {
      cout << "0\n";
    } else {
      cout << r - l + 1 << '\n';
    }
  }
  return 0;
}
