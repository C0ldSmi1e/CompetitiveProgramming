/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-16 07:27:04
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1905/problem/D
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
    vector<int> a(2 * n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i + n] = a[i];
    }
    deque<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      while ((int) q.size() > 0 && q.back().first >= a[i]) {
        q.pop_back();
      }
      q.push_back(make_pair(a[i], i));
    }
    long long cur = 0;
    for (int i = 1; i < (int) q.size(); i++) {
      cur += 1ll * q[i].first * (q[i].second - q[i - 1].second);
    }
    long long res = 0;
    for (int i = n; i < 2 * n; i++) {
      if ((int) q.size() > 0 && i - q.front().second >= n) {
        auto [x, j] = q.front();
        q.pop_front();
        if ((int) q.size() > 0) {
          cur -= 1ll * q.front().first * (q.front().second - j);
        }
      }
      while ((int) q.size() > 0 && q.back().first >= a[i]) {
        auto [x, j] = q.back();
        q.pop_back();
        if ((int) q.size()) {
          cur -= 1ll * x * (j - q.back().second);
        }
      }
      if ((int) q.size() > 0) {
        cur += 1ll * a[i] * (i - q.back().second);
      }
      q.push_back(make_pair(a[i], i));
      res = max(res, cur + n);
    }
    cout << res << '\n';
  }
  return 0;
}
