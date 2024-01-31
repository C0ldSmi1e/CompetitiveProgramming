/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-17 08:46:44
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START112B/problems/LOGICIAN
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
    bool flag = true;
    for (int i = 0; i < n; i++) {
      flag &= (s[i] == '1');
      if (!flag) {
        cout << "NO\n";
      } else {
        if (i + 1 < n) {
          cout << "IDK\n";
        } else {
          cout << "YES\n";
        }
      }
    }
  }
  return 0;
}
