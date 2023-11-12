/**
 * Author: C0ldSmi1e
 * Created Time: 2023-10-25 14:41:53
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1883/problem/E
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    vector<int> k(n - 1);
    for (int i = 0, pre = 0; i < n - 1; i++) {
      int x = 0;
      long long t1 = a[i];
      long long t2 = a[i + 1];
      while (t2 < t1) {
        t2 *= 2;
        x += 1;
      }
      // a[i+1] * 2^x >= a[i]
      // a[i+1] * 2^x * 2^pre >= a[i] * 2^pre
      x += pre;
      long long y = a[i + 1] / a[i];
      while (y > 1 && x > 0) {
        x -= 1;
        y /= 2;
      }
      k[i] = max(0, x);
      pre = k[i];
    }
    debug(k);
    cout << accumulate(k.begin(), k.end(), 0LL) << '\n';
  }
  return 0;
}

