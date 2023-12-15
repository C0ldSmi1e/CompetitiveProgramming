/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-07 21:34:27
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START111B/problems/RANGEGAME
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
    long long l, r, p;
    cin >> l >> r >> p;
    --l;
    long long c = 0;
    long long x = 1;
    long long res = 0;
    while (x <= r) {
      long long cnt = (r / x - l / x) - (r / x / p - l / x / p);
      if (cnt & 1) {
        res ^= c;
      }
      c += 1;
      if (x <= r / p) {
        x *= p;
      } else {
        break;
      }
    }
    cout << (res != 0 ? "First\n" : "Second\n");
  }
  return 0;
}

