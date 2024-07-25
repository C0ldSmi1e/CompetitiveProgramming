/**
 * Author: C0ldSmi1e
 * Created Time: 02/21/2024 11:50:36 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1926/problem/B
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
    vector<string> g(n);
    for (auto& s : g) {
      cin >> s;
    }
    int f = 0, l = 0;
    for (int i = 0; i < n; i++) {
      int cnt = count(g[i].begin(), g[i].end(), '1');
      if (f == 0 && cnt > 0) {
        f = cnt;
      }
      if (cnt > 0) {
        l = cnt;
      }
    }
    cout << (f == l ? "SQUARE\n" : "TRIANGLE\n");
  }
  return 0;
}
