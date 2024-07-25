/**
 * Author: C0ldSmi1e
 * Created Time: 03/07/2024 09:01:44 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc343/tasks/abc343_d
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

  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  map<long long, int> mp;
  mp[0] = n;
  set<long long> S{0};
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x;
    mp[a[x]] -= 1;
    if (mp[a[x]] == 0) {
      S.erase(a[x]);
    }
    a[x] += y;
    if (mp[a[x]] == 0) {
      S.insert(a[x]);
    }
    mp[a[x]] += 1;
    cout << (int) S.size() << '\n';
  }
  return 0;
}
