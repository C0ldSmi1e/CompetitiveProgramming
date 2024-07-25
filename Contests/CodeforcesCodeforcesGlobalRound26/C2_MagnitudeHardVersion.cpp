/**
 * Author: C0ldSmi1e
 * Created Time: 06/10/2024 04:00:41 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1984/problem/C2
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
    const int mod = 998244353;
    map<long long, int> b;
    b[a[0]] += 1;
    b[abs(a[0])] += 1;
    for (int i = 1; i < n; i++) {
      map<long long, int> nb;
      auto [x, y] = *b.begin();
      long long s = x + a[i];
      nb[s] = (nb[s] + y) % mod;
      nb[abs(s)] = (nb[abs(s)] + y) % mod;
      if ((int) b.size() == 1) {
        swap(b, nb);
        continue;
      }
      auto [xx, yy] = *b.rbegin();
      long long ss = xx + a[i];
      nb[ss] = (nb[ss] + yy) % mod;
      nb[abs(ss)] = (nb[abs(ss)] + yy) % mod;
      swap(b, nb);
      debug(b);
    }
    long long ans = 0;
    int cnt = 0;
    for (auto& [u, v] : b) {
      if (abs(u) >= ans) {
        ans = u;
        cnt = v;
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}


