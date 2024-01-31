/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-27 06:30:36
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START114A/problems/MINRPC
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
    string res(n, 'P');
    int cnt = count(s.begin(), s.end(), 'R');
    if (cnt > n / 2) {
      cout << res << '\n';
      continue;
    }
    for (int i = n - 1; i >= 0; i--) {
      if (cnt <= n / 2) {
        if (s[i] == 'S') {
          res[i] = 'R';
          cnt += 1;
        }
        if (s[i] == 'P') {
          res[i] = 'S';
          cnt += 1;
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}
