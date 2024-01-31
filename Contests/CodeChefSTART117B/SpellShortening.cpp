/**
 * Author: C0ldSmi1e
 * Created Time: 01/17/2024 06:32:17 AM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START117B/problems/SHORTSPELL
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
    int p = -1;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] > s[i + 1]) {
        p = i;
        break;
      }
    }
    if (p == -1) {
      s.pop_back();
    } else {
      s = s.substr(0, p) + s.substr(p + 1);
    }
    cout << s << '\n';
  }
  return 0;
}
