/**
 * Author: C0ldSmi1e
 * Created Time: 03/12/2024 10:13:42 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1941/problem/C
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
    vector<int> c(3);
    for (int i = 0; i < n; i++) {
      if (i + 2 < n && s.substr(i, 3) == "map") {
        c[0] += 1;
      }
      if (i + 2 < n && s.substr(i, 3) == "pie") {
        c[1] += 1;
      }
      if (i + 4 < n && s.substr(i, 5) == "mapie") {
        c[2] += 1;
      }
    }
    cout << c[0] + c[1] - c[2] << '\n';
  }
  return 0;
}
