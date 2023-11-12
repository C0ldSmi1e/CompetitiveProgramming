/**
 * Author: C0ldSmi1e
 * Created Time: 2023-10-28 09:23:46
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1890/problem/E1
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
    int n, m, kk;
    cin >> n >> m >> kk;
    vector<vector<pair<int, int>>> R(n);
    for (int i = 0; i < m; i++) {
      int l, r;
      cin >> l >> r;
      --l;
      --r;
      R[l].emplace_back(make_pair(r, i));
    }
    vector<vector<int>> idx(n);
    multiset<pair<int, int>> S;
    for (int i = 0; i < n; i++) {
      for (auto& r : R[i]) {
        S.insert(r);
      }
      while ((int) S.size() > 0 && (*S.begin()).first < i) {
        S.erase(S.begin());
      }
      int cnt = 0;
      for (auto& [x, y] : S) {
        cnt += 1;
        idx[i].emplace_back(y);
        if (cnt >= 3) {
          break;
        }
      }
    }
    int c0 = 0;
    map<int, int> mp1;
    map<pair<int, int>, int> mp2;
    for (int i = 0; i < n; i++) {
      c0 += (int) (idx[i].size() == 0);
      if ((int) idx[i].size() == 1) {
        mp1[idx[i][0]] += 1;
      }
      if ((int) idx[i].size() == 2) {
        mp2[make_pair(idx[i][0], idx[i][1])] += 1;
      }
    }
    for (int i = 0; i < n; i++) {
      //debug(idx[i]);
    }
    int mx1 = 0, mx2 = 0;
    for (auto& [x, cnt] : mp1) {
      if (cnt > mx1) {
        mx2 = mx1;
        mx1 = cnt;
      } else if (cnt > mx2) {
        mx2 = cnt;
      }
    }
    int res = c0 + mx1 + mx2;
    for (auto& [p, cnt] : mp2) {
      res = max(res, c0 + cnt + mp1[p.first] + mp1[p.second]);
    }
    cout << res << '\n';
  }
  return 0;
}
