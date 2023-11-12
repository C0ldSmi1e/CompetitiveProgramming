/**
 * Author: C0ldSmi1e
 * Created Time: 2023-10-30 07:47:57
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1891/problem/B
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    vector<int> b(m);
    vector<bool> st(31);
    for (auto& u : b) {
      cin >> u;
      st[u] = true;
    }
    vector<int> c;
    vector<bool> used(31);
    for (auto& bit : b) {
      if (st[bit]) {
        if (!used[bit]) {
          used[bit] = true;
          c.emplace_back(bit);
        }
      }
    }
    debug(c);
    for (auto& u : a) {
      for (auto& bit : c) {
        if (u % (1 << bit) == 0) {
          u |= (1 << (bit - 1));
        }
      }
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
