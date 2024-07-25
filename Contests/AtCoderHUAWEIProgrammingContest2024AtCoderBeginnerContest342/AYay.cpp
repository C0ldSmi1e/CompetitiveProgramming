/**
 * Author: C0ldSmi1e
 * Created Time: 03/06/2024 03:04:19 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc342/tasks/abc342_a
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
  for (int i = 0; i < (int) s.size(); i++) {
    if (count(s.begin(), s.end(), s[i]) == 1) {
      cout << i + 1 << '\n';
      return 0;
    }
  }
  return 0;
}
