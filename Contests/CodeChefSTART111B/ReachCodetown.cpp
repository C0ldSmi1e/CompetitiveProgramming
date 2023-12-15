/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-06 06:35:57
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START111B/problems/CODETOWN
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

  set<char> S{'A', 'E', 'I', 'O', 'U'};
  vector<bool> t(8);
  t[1] = t[3] = t[5] = true;
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    bool flag = true;
    for (int i = 0; i < 8; i++) {
      if (!((S.count(s[i]) && t[i] == 1) || (!S.count(s[i]) && t[i] == 0))) {
        flag = false;
      }
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
