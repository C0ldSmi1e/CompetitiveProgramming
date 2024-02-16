/**
 * Author: C0ldSmi1e
 * Created Time: 02/05/2024 11:07:40 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc339/tasks/abc339_f
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

/*
random_device rd;
mt19937_64 rng{rd()};
*/

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// [l, r]
template <typename T>
T Rand(T l, T r) {
  uniform_int_distribution<T> d(l, r);
  return d(rng);
}

template <typename T>
T RealRand(T l, T r) {
  uniform_real_distribution<T> d(l, r);
  return d(rng);
}

// long long Rand(long long l, long long r) {
//   return (rng() % (r + 1 - l)) + l;
// }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  const int m = 30;
  vector<int> rd(m);
  for (auto& u : rd) {
    u = Rand((int) 1e9, (int) 2e9);
  }
  int n;
  cin >> n;
  vector<vector<int>> g(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      for (auto& c : s) {
        g[i][j] = (1ll * g[i][j] * 10 + (int) (c - '0')) % rd[j];
      }
    }
  }
  sort(g.begin(), g.end());
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vector<int> b(m);
      for (int k = 0; k < m; k++) {
        b[k] = 1ll * g[i][k] * g[j][k] % rd[k];
      }
      res += (int) (upper_bound(g.begin(), g.end(), b) - lower_bound(g.begin(), g.end(), b));
    }
  }
  cout << res << '\n';
  return 0;
}
