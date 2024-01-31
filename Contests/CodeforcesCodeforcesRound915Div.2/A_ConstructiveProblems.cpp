/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-16 06:38:29
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1905/problem/A
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
    cout << max(n, m) << '\n';
  }
  return 0;
}
