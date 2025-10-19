/**
 * Author: C0ldSmi1e
 * Created Time: 10/18/2025 09:42:35 PM
**/

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
    int mx = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      mx = max(mx, x);
    }
    cout << mx << '\n';
  }
  return 0;
}
