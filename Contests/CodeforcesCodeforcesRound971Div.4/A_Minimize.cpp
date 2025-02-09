/**
 * Author: C0ldSmi1e
 * Created Time: 09/09/2024 02:49:25 PM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/2009/problem/A
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
    int a, b;
    cin >> a >> b;
    cout << b - a << '\n';
  }
  return 0;
}
