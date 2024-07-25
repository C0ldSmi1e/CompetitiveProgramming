/**
 * Author: C0ldSmi1e
 * Created Time: 03/28/2024 07:46:16 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1950/problem/A
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
    int a, b, c;
    cin >> a >> b >> c;
    if (a < b && b < c) {
      cout << "STAIR\n";
    } else if (a < b && b > c) {
      cout << "PEAK\n";
    } else {
      cout << "NONE\n";
    }
  }
  return 0;
}
