/**
 * Author: C0ldSmi1e
 * Created Time: 03/27/2024 09:12:42 PM
**/

// time-limit: 3000
// problem-url: https://atcoder.jp/contests/abc346/tasks/abc346_f
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

  long long k;
  cin >> k;
  string s;
  cin >> s;
  string t;
  cin >> t;
  int n = (int) s.size();
  int m = (int) t.size();
  vector<vector<int>> idx(26);
  for (int i = 0; i < n; i++) {
    idx[(int) (s[i] - 'a')].emplace_back(i);
  }
  long long l = 0, r = (long long) 4e18;
  auto Check = [&](long long x) -> bool {
    long long cur = 0;
    long long pos = -1;
    debug(x);
    for (int i = 0; i < m; i++) {
      int c = (int) (t[i] - 'a');
      if ((int) idx[c].size() == 0) {
        return false;
      }
      pos += 1;
      if (pos >= n) {
        cur += 1;
        pos = 0;
      }
      long long xx = x;
      int p = (int) (lower_bound(idx[c].begin(), idx[c].end(), pos) - idx[c].begin());
      int left = (int) idx[c].size() - p;
      if (left >= xx) {
        pos = idx[c][p + xx - 1];
      } else {
        xx -= left;
        cur += 1;
        if (xx % (int) idx[c].size() == 0) {
          cur += xx / (int) idx[c].size() - 1;
          pos = idx[c].back();
        } else {
          cur += xx / (int) idx[c].size();
          xx %= (int) idx[c].size();
          pos = idx[c][xx - 1];
        }
      }
      if (cur >= k) {
        return false;
      }
    }
    return cur < k;
  };
  while (l < r) {
    long long mid = (l + r + 1) >> 1;
    if (Check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << r << '\n';
  return 0;
}
