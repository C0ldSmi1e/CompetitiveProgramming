/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-26 06:38:37
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1900/problem/A
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
    int res = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
      if (s[i] == '#') {
        continue;
      }
      int j = i;
      while (j < n && s[j] == '.') {
        j += 1;
      }
      if (j - i <= 2) {
        res += j - i;
      } else {
        flag = true;
      }
      i = j;
    }
    if (flag) {
      res = 2;
    }
    cout << res << '\n';
  }
  return 0;
}
