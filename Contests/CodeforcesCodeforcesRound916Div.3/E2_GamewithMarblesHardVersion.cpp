// time-limit: 3500
// problem-url: https://codeforces.com/contest/1914/problem/E2
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
    for (auto&u : a) {
      cin >> u;
    }
    vector<int> b(n);
    for (auto& u : b) {
      cin >> u;
    }
    long long res = 0;
    for (auto& u : b) {
      res += 1 - u;
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return a[i] + b[i] > a[j] + b[j];
    });
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        res += (a[order[i]] + b[order[i]] - 2);
      }
    }
    cout << res << '\n';
  }
  return 0;
}
