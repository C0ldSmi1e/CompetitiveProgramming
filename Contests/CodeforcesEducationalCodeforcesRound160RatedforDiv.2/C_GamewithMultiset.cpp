/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-18 06:49:44
**/

// time-limit: 1500
// problem-url: https://codeforces.com/contest/1913/problem/C
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

  vector<long long> cnt(30);
  int q;
  cin >> q;
  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      cnt[x] += 1;
    } else {
      long long need = 0;
      for (int bit = 30; bit >= 0; bit--) {
        if ((x >> bit) & 1) {
          need += 1;
        }
        long long take = min(need, cnt[bit]);
        need -= take;
        need <<= 1;
      }
      cout << (need <= 0 ? "YES\n" : "NO\n");
    }
  }
  return 0;
}
