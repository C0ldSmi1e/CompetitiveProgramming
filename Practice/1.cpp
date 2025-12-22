/**
 * Author: C0ldSmi1e
 * Created Time: 12/21/2025 10:18:43 PM
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
    int l, a, b;
    cin >> l >> a >> b;
    int ans = a;
    set<int> S{a};
    do {
      a = (a + b) % l;
      ans = max(ans, a);
    } while (!S.count(a));
    cout << ans << '\n';
  }
  return 0;
}
