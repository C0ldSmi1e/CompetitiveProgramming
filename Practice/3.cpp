/**
 * Author: C0ldSmi1e
 * Created Time: 03/25/2025 07:39:15 AM
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

  long long n, b;
  cin >> n >> b;
  map<long long, long long> mp;
  for (long long i = 2; i <= b / i; i++) {
    if (b % i == 0) {
      while (b % i == 0) {
        b /= i;
        mp[i] += 1;
      }
    }
  }
  if (b > 1) {
    mp[b] = 1;
  }
  long long mn = (long long) 1e18;
  for (auto& [x, c] : mp) {
    long long z = x;
    long long cnt = 0;
    while (true) {
      cnt += n / z;
      if (z <= n / x) {
        z *= x;
        continue;
      }
      break;
    }
    mn = min(mn, cnt / c);
  }
  cout << mn << '\n';
  return 0;
}
