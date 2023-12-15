/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-26 07:39:52
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1900/problem/D
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

  const int N = 100010;
  vector<int> phi(N);
  iota(phi.begin(), phi.end(), 0);
  for (int i = 1; i < N; i++) {
    for (int j = 2 * i; j < N; j += i) {
      phi[j] -= phi[i];
    }
  }
  vector<vector<int>> factors(N);
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      factors[j].emplace_back(i);
    }
  }
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    sort(a.begin(), a.end());
    vector<int> cnt(N);
    long long res = 0;
    for (int i = 0; i < n; i++) {
      for (auto& fac : factors[a[i]]) {
        res += 1ll * phi[fac] * cnt[fac] * (n - i - 1);
        cnt[fac] += 1;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
