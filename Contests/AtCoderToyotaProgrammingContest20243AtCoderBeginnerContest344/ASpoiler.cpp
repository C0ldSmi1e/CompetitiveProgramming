/**
 * Author: C0ldSmi1e
 * Created Time: 03/14/2024 03:51:08 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc344/tasks/abc344_a
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

  string s;
  cin >> s;
  int n = (int) s.size();
  int l = -1, r = n;
  for (int i = 0; i < n; i++) {
    if (s[i] == '|') {
      l = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '|') {
      r = i;
      break;
    }
  }
  cout << s.substr(0, l) + s.substr(r + 1);
  return 0;
}
