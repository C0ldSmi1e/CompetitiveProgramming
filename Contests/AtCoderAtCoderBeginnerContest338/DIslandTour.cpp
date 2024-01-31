/**
 * Author: C0ldSmi1e
 * Created Time: 01/30/2024 03:52:31 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc338/tasks/abc338_d
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

  int n, m;
  cin >> n >> m;
  vector<int> x(m);
  vector<long long> w(n);
  long long pref = 0;
  for (int i = 0; i < m; i++) {
    cin >> x[i];
    x[i] -= 1;
    if (i > 0) {
      int a = abs(x[i] - x[i - 1]);
      int b = n - a;
      if (a < b) {
        if (x[i - 1] < x[i]) {
          w[x[i - 1]] -= a;
          w[x[i - 1]] += b;
          w[x[i]] -= b;
          w[x[i]] += a;
          if (x[i - 1] == 0) {
            pref += b;
          } else {
            pref += a;
          }
        } else {
          w[x[i]] -= a;
          w[x[i]] += b;
          w[x[i - 1]] -= b;
          w[x[i - 1]] += a;
          if (x[i] == 0) {
            pref += b;
          } else {
            pref += a;
          }
        }
      } else {
        if (x[i - 1] < x[i]) {
          w[x[i - 1]] += b;
          w[x[i - 1]] -= a;
          w[x[i]] += a;
          w[x[i]] -= b;
          if (x[i - 1] == 0) {
            pref += b;
          } else {
            pref += a;
          }
        } else {
          w[x[i]] -= a;
          w[x[i]] += b;
          w[x[i - 1]] -= b;
          w[x[i - 1]] += a;
          if (x[i] == 0) {
            pref += b;
          } else {
            pref += a;
          }
        }
      }
    }
  }
  long long res = pref;
  for (int i = 1; i < n; i++) {
    pref += w[i];
    res = min(res, pref);
  }
  cout << res << '\n';
  return 0;
}
