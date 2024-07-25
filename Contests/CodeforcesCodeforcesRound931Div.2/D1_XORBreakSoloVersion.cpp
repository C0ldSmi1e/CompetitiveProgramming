/**
 * Author: C0ldSmi1e
 * Created Time: 03/01/2024 07:34:48 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1934/problem/D1
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
    long long n, m;
    cin >> n >> m;
    for (int i = 63; i >= 0; i--) {
      cout << ((n >> i) & 1);
    }
    cout << '\n';
    for (int i = 63; i >= 0; i--) {
      cout << ((m >> i) & 1);
    }
    cout << '\n';
  }
  return 0;
}
