/**
 * Author: C0ldSmi1e
 * Created Time: 02/01/2024 11:26:35 PM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1918/problem/A
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
    int n, m;
    cin >> n >> m;
    int res = n * (m / 2);
    cout << res << '\n';
  }
  return 0;
}
