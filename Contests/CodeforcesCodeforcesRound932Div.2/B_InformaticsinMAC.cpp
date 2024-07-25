/**
 * Author: C0ldSmi1e
 * Created Time: 03/08/2024 08:47:43 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1935/problem/B
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
    map<int, int> lmp, rmp;
    set<int> l, r;
    for (int i = 0; i < n; i++) {
      l.insert(i);
      r.insert(i);
    }
    for (auto& u : a) {
      cin >> u;
      auto it = r.find(u);
      if (it != r.end()) {
        r.erase(it);
      }
      rmp[u] += 1;
    }
    bool flag = false;
    for (int i = 0; i < n - 1; i++) {
      if (lmp[a[i]] == 0) {
        l.erase(l.find(a[i]));
      }
      lmp[a[i]] += 1;
      rmp[a[i]] -= 1;
      if (rmp[a[i]] == 0) {
        r.insert(a[i]);
      }
      if (*l.begin() == *r.begin()) {
        flag = true;
        cout << "2\n";
        cout << "1 " << i + 1 << '\n';
        cout << i + 2 << ' ' << n << '\n';
        break;
      }
    }
    if (!flag) {
      cout << "-1\n";
    }
  }
  return 0;
}
