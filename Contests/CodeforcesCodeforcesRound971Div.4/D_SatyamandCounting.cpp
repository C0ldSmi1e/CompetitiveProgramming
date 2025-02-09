/**
 * Author: C0ldSmi1e
 * Created Time: 10/04/2024 10:55:37 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/2009/problem/D
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
    vector<set<int>> x(2);
    for (int i = 0; i < n; i++) {
      int xx, y;
      cin >> xx >> y;
      x[y].emplace(xx);
    }
    long long ans = 0;
    for (int i = 0; i < 2; i++) {
      for (auto& u : x[i]) {
        if (x[1 - i].count(u - 1) && x[1 - i].count(u + 1)) {
          ans += 1;
        }
        if (x[1 - i].count(u)) {
          ans += (int) (x[1 - i].size()) - 1;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
