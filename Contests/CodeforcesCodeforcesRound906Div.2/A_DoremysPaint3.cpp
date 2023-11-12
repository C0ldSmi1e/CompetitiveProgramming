/**
 * Author: C0ldSmi1e
 * Created Time: 2023-10-28 07:37:51
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1890/problem/A
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
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (auto& u : a) {
      cin >> u;
      mp[u] += 1;
    }
    bool flag = false;
    if ((int) mp.size() == 1) {
      flag = true;
    }
    if ((int) mp.size() == 2) {
      int c1 = 0;
      int c2 = 0;
      for (auto& [x, y] : mp) {
        if (c1 == 0) {
          c1 = y;
        } else {
          c2 = y;
        }
      }
      flag |= (abs(c1 - c2) <= 1);
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
