/**
 * Author: C0ldSmi1e
 * Created Time: 2023-10-30 08:00:30
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1891/problem/C
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
    sort(a.begin(), a.end());
    long long res = 0;
    int i = 0;
    int j = n - 1;
    long long cur = 0;
    while (i <= j) {
      if (cur >= a[j]) {
        res += 1;
        cur = 0;
        a[j] = 0;
        j -= 1;
        continue;
      }
      if (i < j) {
        long long take = min(a[i], a[j] - cur);
        cur += take;
        res += take;
        a[i] -= take;
        if (cur >= a[j]) {
          res += 1;
          j -= 1;
          cur = 0;
        }
        if (a[i] == 0) {
          i += 1;
        }
      } else {
        debug(cur, a[i]);
        res += min(a[i], (a[i] - cur + 1) / 2 + 1);
        a[i] = 0;
        i += 1;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
