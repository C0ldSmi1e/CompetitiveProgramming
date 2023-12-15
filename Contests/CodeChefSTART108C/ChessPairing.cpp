/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-15 07:12:40
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START108C/problems/CHESS_PAIR
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    n *= 2;
    int y = n - x;
    if (2 * y >= n) {
      cout << "0\n";
    } else {
      cout << x - y << '\n';
    }
  }
  return 0;
}
