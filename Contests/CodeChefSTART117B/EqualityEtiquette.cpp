/**
 * Author: C0ldSmi1e
 * Created Time: 01/17/2024 06:52:48 AM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START117B/problems/EQUAL2
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
  map<long long, long long> mp;
  while (T--) {
    long long a, b;
    cin >> a >> b;
    if (mp.count(abs(a - b))) {
      cout << mp[abs(a - b)] << '\n';
      continue;
    }
    auto Get = [&](long long x) -> long long {
      if (x == 0) {
        return 0;
      }
      long long l = 1, r = x;
      while (l < r) {
        long long mid = (l + r) >> 1;
        if ((1 + mid) * mid / 2 >= x) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      long long sum = (1 + r) * r / 2;
      assert(sum >= x);
      while ((sum - x) % 2 != 0) {
        r += 1;
        sum += r;
      }
      return r;
    };
    cout << Get(abs(a - b)) << '\n';
  }
  return 0;
}
