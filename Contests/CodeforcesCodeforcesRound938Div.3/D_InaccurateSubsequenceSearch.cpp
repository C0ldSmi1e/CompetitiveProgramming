/**
 * Author: C0ldSmi1e
 * Created Time: 04/08/2024 08:02:07 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1955/problem/D
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    vector<int> b(m);
    map<int, int> mpb;
    for (auto& u : b) {
      cin >> u;
      mpb[u] += 1;
    }
    map<int, int> mpa;
    int cnt = 0;
    for (int i = 0; i < m - 1; i++) {
      if (mpa[a[i]] < mpb[a[i]]) {
        cnt += 1;
      }
      mpa[a[i]] += 1;
    }
    int ans = 0;
    for (int i = m - 1; i < n; i++) {
      if (mpa[a[i]] < mpb[a[i]]) {
        cnt += 1;
      }
      mpa[a[i]] += 1;
      ans += (int) (cnt >= k);
      mpa[a[i - (m - 1)]] -= 1;
      if (mpa[a[i - (m - 1)]] < mpb[a[i - (m - 1)]]) {
        cnt -= 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
