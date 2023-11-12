/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-07 07:22:48
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1894/problem/D
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
    for (auto& u : b) {
      cin >> u;
    }
    sort(b.rbegin(), b.rend());
    vector<int> c;
    int i = 0;
    int j = 0;
    while (i < n) {
      if (j >= m) {
        c.emplace_back(a[i]);
        i += 1;
        continue;
      }
      if (a[i] < b[j]) {
        c.emplace_back(b[j]);
        j += 1;
      } else {
        c.emplace_back(a[i]);
        i += 1;
      }
    }
    while (j < m) {
      c.emplace_back(b[j]);
      j += 1;
    }
    for (auto& u : c) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}

