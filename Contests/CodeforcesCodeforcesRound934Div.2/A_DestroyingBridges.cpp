/**
 * Author: C0ldSmi1e
 * Created Time: 03/16/2024 07:37:22 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1944/problem/A
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
    int k;
    cin >> k;
    cout << (k >= n - 1 ? 1 : n) << '\n';
  }
  return 0;
}
