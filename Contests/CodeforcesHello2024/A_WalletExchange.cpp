/**
 * Author: C0ldSmi1e
 * Created Time: 01/06/2024 06:39:18 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1919/problem/A
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
    cout << ((a + b) % 2 == 0 ? "Bob\n" : "Alice\n");
  }
  return 0;
}
