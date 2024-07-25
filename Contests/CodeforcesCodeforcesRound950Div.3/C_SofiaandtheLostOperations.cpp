/**
 * Author: C0ldSmi1e
 * Created Time: 06/08/2024 09:14:39 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1980/problem/C
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
    vector<int> b(n);
    for (auto& u : b) {
      cin >> u;
    }
    int m;
    cin >> m;
    vector<int> c(m);
    map<int, int> mp;
    for (auto& u : c) {
      cin >> u;
      mp[u] += 1;
    }
    if (count(b.begin(), b.end(), c.back()) == 0) {
      cout << "NO\n";
      continue;
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        if (mp[b[i]] > 0) {
          mp[b[i]] -= 1;
          continue;
        }
        flag = false;
        break;
      }
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
