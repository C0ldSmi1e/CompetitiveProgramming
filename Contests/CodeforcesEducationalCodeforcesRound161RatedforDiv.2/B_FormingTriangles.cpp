/**
 * Author: C0ldSmi1e
 * Created Time: 01/18/2024 06:43:54 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1922/problem/B
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
    vector<long long> cnt(n + 1);
    for (auto& u : a) {
      cin >> u;
      cnt[u] += 1;
    }
    long long res = 0;
    long long pref = 0;
    for (int i = 0; i <= n; i++) {
      res += cnt[i] * (cnt[i] - 1) / 2 * pref;
      res += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
      pref += cnt[i];
    }
    cout << res << '\n';
  }
  return 0;
}
