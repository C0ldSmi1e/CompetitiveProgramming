/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-05 12:51:39
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1907/problem/G
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
    string s;
    cin >> s;
    vector<int> a(n);
    vector<int> din(n);
    for (auto& u : a) {
      cin >> u;
      --u;
      din[u] += 1;
    }
    vector<int> q;
    for (int i = 0; i < n; i++) {
      if (din[i] == 0) {
        q.emplace_back(i);
      }
    }
    vector<int> res;
    for (int qq = 0; qq < (int) q.size(); qq++) {
      int u = q[qq];
      if (s[u] == '1') {
        res.emplace_back(u);
        s[u] ^= 1;
        s[a[u]] ^= 1;
      }
      if (--din[a[u]] == 0) {
        q.emplace_back(a[u]);
      }
    }
    bool flag = true;
    for (int u = 0; u < n; u++) {
      if (din[u] != 0) {
        vector<int> circle;
        vector<int> cnt(2);
        int t = 0;
        int v = u;
        while (din[v]) {
          din[v] = 0;
          if (s[v] == '1') {
            t ^= 1;
          }
          cnt[t] += 1;
          circle.emplace_back(v);
          v = a[v];
        }
        if (t == 1) {
          flag = false;
          break;
        }
        for (auto& u : circle) {
          if (s[u] == '1') {
            t ^= 1;
          }
          if ((cnt[0] <= cnt[1] && t == 0) || (cnt[0] > cnt[1] && t == 1)) {
            res.emplace_back(u);
          }
        }
      }
    }
    if (!flag) {
      cout << "-1\n";
      continue;
    }
    cout << (int) res.size() << '\n';
    for (auto& u : res) {
      cout << u + 1 << ' ';
    }
    cout << '\n';
  }
  return 0;
}
