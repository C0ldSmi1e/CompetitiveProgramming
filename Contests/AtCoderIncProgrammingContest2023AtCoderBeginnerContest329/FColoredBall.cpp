/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-18 23:40:59
**/

// time-limit: 4000
// problem-url: https://atcoder.jp/contests/abc329/tasks/abc329_f
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

  int n, q;
  cin >> n >> q;
  vector<set<int>> S(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    S[i].insert(x);
  }
  while (q--) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    if ((int) S[a].size() > (int) S[b].size()) {
      swap(S[a], S[b]);
    }
    for (auto& u : S[a]) {
      S[b].insert(u);
    }
    S[a].clear();
    cout << (int) S[b].size() << '\n';
  }
  return 0;
}
