/**
 * Author: C0ldSmi1e
 * Created Time: 04/08/2024 08:38:05 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1955/problem/F
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
    array<int, 4> p;
    for (auto& u : p) {
      cin >> u;
    }
    int ans = p[0] / 2 + p[1] / 2 + p[2] / 2 + p[3] / 2;
    p[0] %= 2;
    p[1] %= 2;
    p[2] %= 2;
    p[3] %= 2;
    ans += min({p[0], p[1], p[2]});
    cout << ans << '\n';
  }
  return 0;
}
