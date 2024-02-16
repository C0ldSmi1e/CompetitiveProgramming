/**
 * Author: C0ldSmi1e
 * Created Time: 02/13/2024 06:43:38 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1931/problem/B
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
    long long sum = 0;
    for (auto& u : a) {
      cin >> u;
      sum += u;
    }
    bool flag = true;
    long long extra = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] >= sum / n) {
        extra += a[i] - sum / n;
      } else {
        long long need = sum / n - a[i];
        if (need > extra) {
          flag = false;
        } else {
          extra -= need;
        }
      }
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
