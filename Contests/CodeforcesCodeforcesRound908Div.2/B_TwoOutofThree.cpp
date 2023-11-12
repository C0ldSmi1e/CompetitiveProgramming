// time-limit: 3000
// problem-url: https://codeforces.com/contest/1894/problem/B
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
    vector<int> cnt(101);
    for (auto& u : a) {
      cin >> u;
      cnt[u] += 1;
    }
    int x = -1;
    int y = -1;
    for (int i = 0; i <= 100; i++) {
      if (cnt[i] > 1) {
        if (x != -1) {
          y = i;
        } else {
          x = i;
        }
      }
    }
    if (y == -1) {
      cout << "-1\n";
      continue;
    }
    vector<int> b(n, 1);
    for (int i = 0; i < n; i++) {
      if (a[i] == x) {
        b[i] = 2;
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      if (a[i] == y) {
        b[i] = 3;
        break;
      }
    }
    for (auto& u : b) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
