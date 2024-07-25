/**
 * Author: C0ldSmi1e
 * Created Time: 03/14/2024 03:54:43 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc344/tasks/abc344_c
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

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& u : a) {
    cin >> u;
  }
  int m;
  cin >> m;
  vector<int> b(m);
  for (auto& u : b) {
    cin >> u;
  }
  int k;
  cin >> k;
  vector<int> c(k);
  for (auto& u : c) {
    cin >> u;
  }
  set<int> S;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int l = 0; l < k; l++) {
        S.insert(a[i] + b[j] + c[l]);
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << (S.count(x) > 0 ? "Yes\n" : "No\n");
  }
  return 0;
}
