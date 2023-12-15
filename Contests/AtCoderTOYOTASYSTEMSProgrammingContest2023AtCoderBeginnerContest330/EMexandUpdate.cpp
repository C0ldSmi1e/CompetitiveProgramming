/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-26 11:08:55
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc330/tasks/abc330_e
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

  int n, q;
  cin >> n >> q;
  set<int> S;
  for (int i = 0; i <= n; i++) {
    S.insert(i);
  }
  map<int, int> mp;
  vector<int> a(n);
  for (auto& u : a) {
    cin >> u;
    mp[u] += 1;
    S.erase(u);
  }
  while (q--) {
    int i, x;
    cin >> i >> x;
    i -= 1;
    mp[a[i]] -= 1;
    if (mp[a[i]] == 0) {
      S.insert(a[i]);
    }
    a[i] = x;
    mp[a[i]] += 1;
    S.erase(a[i]);
    cout << *S.begin() << '\n';
  }
  return 0;
}
