/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-17 08:58:19
**/

// time-limit: 2000
// problem-url: 
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
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
      cout << i + 1 << ' ' << i + 2 << '\n';
    }
    int x = n - 1;
    while (q--) {
      int y;
      cin >> y;
      if (x == y) {
        cout << "-1 -1 -1\n";
      } else {
        cout << n << ' ' << x << ' ' << y << '\n';
        x = y;
      }
    }
  }
  return 0;
}
