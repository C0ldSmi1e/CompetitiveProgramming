/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-20 20:01:08
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1898/problem/B
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    int last = a[n - 1];
    long long res = 0;
    for (int i = n - 2; i >= 0; i--) {
      int l = 0;
      int r = a[i] - 1;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (a[i] / (mid + 1) + (a[i] % (mid + 1) > 0 ? 1 : 0) > last) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
      last = a[i] / (r + 1);
      res += r;
    }
    cout << res << '\n';
  }
  return 0;
}

