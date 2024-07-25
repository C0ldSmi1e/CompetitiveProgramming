/**
 * Author: C0ldSmi1e
 * Created Time: 06/11/2024 08:13:53 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1985/problem/A
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
    string s, t;
    cin >> s >> t;
    swap(s[0], t[0]);
    cout << s << ' ' << t << '\n';
  }
  return 0;
}
