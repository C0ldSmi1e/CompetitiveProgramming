// time-limit: 1000
// problem-url: https://codeforces.com/contest/1985/problem/E
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
    long long x, y, z, k;
    cin >> x >> y >> z >> k;
    long long ans = 0;
    for (int i = 1; i <= x; i++) {
      for (int j = 1; j <= y; j++) {
        if (k % (i * j) == 0 && (k / (i * j)) <= z) {
          ans = max(ans, (x - i + 1) * (y - j + 1) * (z - k / (i * j) + 1));
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
