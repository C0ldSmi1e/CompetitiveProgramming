/**
 * Author: C0ldSmi1e
 * Created Time: 07/31/2025 10:08:18 AM
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
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    int c0 = count(a.begin(), a.end(), 0);
    int c1 = count(a.begin(), a.end(), 1);
    int t = min(c0, c1);
    c0 -= t;
    c1 -= t;
    int ans = t * 2 + c0;
    ans += accumulate(a.begin(), a.end(), 0) - t;
    cout << ans << '\n';
  }
  return 0;
}
