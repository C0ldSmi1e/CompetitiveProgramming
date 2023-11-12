/**
 * Author: C0ldSmi1e
 * Created Time: 2023-10-25 17:03:08
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1883/problem/G2
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n - 1);
    for (auto& u : a) {
      cin >> u;
    }
    vector<int> b(n);
    multiset<int> S;
    for (auto& u : b) {
      cin >> u;
      S.insert(u);
    }
    int tot = n - 1;
    for (auto& u : a) {
      auto it = S.upper_bound(u);
      if (it != S.end()) {
        S.erase(it);
        tot -= 1;
      }
    }
    long long res = 1LL * min(m, *prev(S.end()) - 1) * tot;
    res += 1LL * max(0, m - *prev(S.end()) + 1) * (tot + 1);
    cout << res << '\n';
  }
  return 0;
}
