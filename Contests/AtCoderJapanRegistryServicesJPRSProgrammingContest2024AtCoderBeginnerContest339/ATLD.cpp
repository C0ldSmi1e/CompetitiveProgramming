/**
 * Author: C0ldSmi1e
 * Created Time: 02/05/2024 03:00:31 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc339/tasks/abc339_a
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
  string t;
  for (int i = (int) s.size() - 1; i >= 0; i--) {
    if (s[i] == '.') {
      break;
    }
    t += s[i];
  }
  reverse(t.begin(), t.end());
  cout << t << '\n';
  return 0;
}
