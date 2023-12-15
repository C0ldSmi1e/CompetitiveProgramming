/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-05 08:45:46
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1907/problem/F
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
    long long INF = (long long) 1e18;
    long long res = INF;
    auto Check = [&]() -> long long {
      int p = -1;
      for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] < a[i]) {
          p = i + 1;
          break;
        }
      }
      if (p >= 0) {
        bool flag = true;
        for (int i = p; i < n - 1; i++) {
          flag &= (a[i + 1] >= a[i]);
        }
        if (flag && a.back() <= a[0]) {
          return n - p;
        }
        return INF;
      }
      return 0;
    };
    auto RevCheck = [&]() -> long long {
      int p = -1;
      for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] > a[i]) {
          p = i + 1;
          break;
        }
      }
      if (p >= 0) {
        bool flag = true;
        for (int i = p; i < n - 1; i++) {
          flag &= (a[i + 1] <= a[i]);
        }
        if (flag && a.back() >= a[0]) {
          return n - p;
        }
        return INF;
      }
      return 0ll;
    };
    res = min(res, Check());
    res = min(res, RevCheck() + 1);
    reverse(a.begin(), a.end());
    res = min(res, 1 + Check());
    res = min(res, 1 + RevCheck() + 1);
    if (res == INF) {
      res = -1;
    }
    cout << res << '\n';
  }
  return 0;
}
