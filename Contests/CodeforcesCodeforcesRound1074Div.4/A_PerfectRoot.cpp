/**
 * Author: C0ldSmi1e
 * Created Time: 01/19/2026 02:49:50 PM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/2185/problem/A
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
    for (int i = 0; i < n; i++) {
      cout << i + 1 << ' ';
    }
    cout << "\n";
  }
  return 0;
}
