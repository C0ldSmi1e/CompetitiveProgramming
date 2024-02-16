/**
 * Author: C0ldSmi1e
 * Created Time: 02/14/2024 10:54:13 AM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc340/tasks/abc340_c
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

  long long n;
  cin >> n;
  map<long long, long long> mp;
  auto Dfs = [&](auto& self, long long u) -> long long {
    if (mp.count(u)) {
      return mp[u];
    }
    if (u == 1) {
      return 0;
    }
    return mp[u] = u + self(self, u / 2) + self(self, (u + 1) / 2);
  };
  cout << Dfs(Dfs, n) << '\n';
  return 0;
}
