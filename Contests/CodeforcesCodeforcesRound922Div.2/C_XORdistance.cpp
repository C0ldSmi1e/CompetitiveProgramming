/**
 * Author: C0ldSmi1e
 * Created Time: 02/02/2024 11:22:28 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1918/problem/C
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
    long long a, b, r;
    cin >> a >> b >> r;
    long long ans = 0;
    for (int bit = 62; bit >= 0; bit--) {
      if (((a >> bit) & 1) != ((b >> bit) & 1)) {
        if ((a >> bit) & 1) {
          swap(a, b);
        }
        long long x = 0;
        for (int bjt = bit - 1; bjt >= 0; bjt--) {
          if (((a >> bjt) & 1) == 0 && ((b >> bjt) & 1) == 1 && (x | (1ll << bjt)) <= r) {
            x |= (1ll << bjt);
          }
        }
        ans = abs(((a ^ x) - (b ^ x)));
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
