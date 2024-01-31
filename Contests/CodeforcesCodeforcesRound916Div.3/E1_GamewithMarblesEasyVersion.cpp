/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-19 07:05:17
**/

// time-limit: 3500
// problem-url: https://codeforces.com/contest/1914/problem/E1
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
    long long d = 0;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
      d += u;
    }
    vector<int> b(n);
    for (auto& u : b) {
      cin >> u;
      d -= u;
    }
    vector<pair<long long, int>> c;
    for (int i = 0; i < n; i++) {
      long long da = 1 - b[i];
      long long db = a[i] - 1;
      c.emplace_back(make_pair(da - db, i));
    }
    sort(c.begin(), c.end());
    for (int i = 0; i < n; i++) {
      if (i & 1) {
        long long db = a[c[i].second] - 1;
        d -= db;
      } else {
        long long da = 1 - b[c[i].second];
        d -= da;
      }
    }
    debug(c);
    cout << d << '\n';
  }
  return 0;
}

