/**
 * Author: C0ldSmi1e
 * Created Time: 01/13/2024 03:17:04 PM
**/

// time-limit: 4000
// problem-url: https://codeforces.com/contest/1920/problem/D
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
    int n, q;
    cin >> n >> q;
    map<long long, int> mp;
    long long m = 0;
    vector<long long> lens;
    while (n--) {
      int t, x;
      cin >> t >> x;
      if (t == 1) {
        mp[m] = x;
        m += 1;
        lens.emplace_back(m);
      } else {
        // m * (x + 1) <= INF
        if (m <= (long long) 2e18 / (x + 1)) {
          m = m * (x + 1);
        } else {
          m = (long long) 2e18;
        }
      }
    }
    debug(mp);
    debug(lens);
    auto Get = [&](long long x) -> int {
      while (!mp.count(x)) {
        auto it = upper_bound(lens.begin(), lens.end(), x + 1);
        if (it != lens.begin()) {
          --it;
          x %= (*it);
        }
      }
      return mp[x];
    };
    while (q--) {
      long long x;
      cin >> x;
      cout << Get(x - 1) << ' ';
    }
    cout << '\n';
  }
  return 0;
}
