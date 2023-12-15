/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-26 11:24:32
**/

// time-limit: 3000
// problem-url: https://atcoder.jp/contests/abc330/tasks/abc330_f
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

  int n;
  long long k;
  cin >> n >> k;
  vector<int> x(n);
  vector<int> y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  ranges::sort(x);
  ranges::sort(y);
  auto rx = x;
  rx[0] = 0;
  auto ry = y;
  for (int i = 1; i < n; i++) {
    rx[i] = rx[i - 1] + (x[n - i] - x[n - i - 1]);
    ry[i] = ry[i - 1] + (y[n - i] - y[n - i - 1]);
  }
  auto Get = [&](vector<int>& idx, long long len) -> long long {
    long long l = 0;
    long long r = len;
    int p = 0;
    while (p < n && idx[p] <= len) {
      p += 1;
    }
    long long tot = 0;
    for (int i = p; i < n; i++) {
      tot += idx[i] - r;
    }
    long long res = tot;
    for (int i = p, j = 0; i < n; i++) {
      long long new_r = idx[i];
      long long new_l = new_r - len;
      tot -= (new_r - r) * (n - i);
      tot += (new_l - l) * j;
      while (idx[j] < new_l) {
        tot += new_l - idx[j];
        j += 1;
      }
      l = new_l;
      r = new_r;
      res = min(res, tot);
    }
    return res;
  };
  auto Check = [&](long long len) -> bool {
    return min(Get(x, len), Get(rx, len)) + min(Get(ry, len), Get(y, len)) <= k;
  };
  long long l = 0;
  long long r = (long long) 2e9;
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (Check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << r << '\n';
  return 0;
}
