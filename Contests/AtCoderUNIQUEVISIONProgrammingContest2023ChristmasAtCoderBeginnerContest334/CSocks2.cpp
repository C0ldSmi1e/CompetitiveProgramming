/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-26 19:43:42
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc334/tasks/abc334_c
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

  int n, k;
  cin >> n >> k;
  vector<int> a(k);
  for (auto& u : a) {
    cin >> u;
  }
  if (k % 2 == 0) {
    long long sum = 0;
    for (int i = 1; i < k; i += 2) {
      sum += a[i] - a[i - 1];
    }
    cout << sum << '\n';
    return 0;
  }
  vector<long long> l(k);
  for (int i = 1; i < k; i += 2) {
    l[i] = a[i] - a[i - 1];
    if (i - 2 >= 0) {
      l[i] += l[i - 2];
    }
  }
  vector<long long> r(k);
  for (int i = k - 2; i >= 0; i -= 2) {
    r[i] = a[i + 1] - a[i];
    if (i + 2 < k) {
      r[i] += r[i + 2];
    }
  }
  long long res = (long long) 2e18;
  for (int i = 0; i < k; i++) {
    long long L = 0;
    long long R = 0;
    if (i & 1) {
      L = (i - 2 >= 0 ? l[i - 2] : 0);
      R = (i + 2 < k ? r[i + 2] : 0);
      if (i + 1 < k && i - 1 >= 0) {
        L += a[i + 1] - a[i - 1];
      }
    } else {
      L = (i - 1 >= 0 ? l[i - 1] : 0);
      R = (i + 1 < k ? r[i + 1] : 0);
    }
    res = min(res, L + R);
  } 
  cout << res << '\n';
  return 0;
}
