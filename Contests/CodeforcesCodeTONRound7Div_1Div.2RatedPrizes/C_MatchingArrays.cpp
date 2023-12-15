/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-25 07:07:34
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1896/problem/C
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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    vector<vector<int>> pos(2 * n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
      pos[a[i]].emplace_back(i);
    }
    vector<int> b(n);
    for (auto& u : b) {
      cin >> u;
      --u;
    }
    sort(b.begin(), b.end());
    vector<int> res(n);
    // [0, x - 1]
    int j = 2 * n - 1;
    for (int i = x - 1; i >= 0; i--) {
      while ((int) pos[j].size() == 0) {
        j -= 1;
      }
      res[pos[j].back()] = b[i];
      pos[j].pop_back();
    }
    // [x, n - 1]
    for (int i = n - 1; i >= x; i--) {
      while ((int) pos[j].size() == 0) {
        j -= 1;
      }
      res[pos[j].back()] = b[i];
      pos[j].pop_back();
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += (int) (a[i] > res[i]);
    }
    if (cnt != x) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (auto& u : res) {
      cout << u + 1 << ' ';
    }
    cout << '\n';
  }
  return 0;
}
