/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-05 11:29:24
**/

// time-limit: 4000
// problem-url: https://atcoder.jp/contests/abc326/tasks/abc326_f
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

  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  for (auto& u : a) {
    cin >> u;
  }
  if (n == 1) {
    if (a[0] == y) {
      cout << "Yes\nL\n";
    } else if (a[0] == -y) {
      cout << "Yes\nR\n";
    } else {
      cout << "No\n";
    }
    return 0;
  }
  vector<int> dx;
  for (int i = 1; i < n; i += 2) {
    dx.emplace_back(a[i]);
  }
  vector<int> dy;
  for (int i = 0; i < n; i += 2) {
    dy.emplace_back(a[i]);
  }
  auto Get = [&](vector<int>& step, int target) -> vector<int> {
    int m = (int) step.size();
    if (m == 0) {
      return {};
    }
    if (m == 1) {
      if (step[0] == target) {
        return {1};
      }
      if (step[0] == -target) {
        return {-1};
      }
      return {};
    }
    int l_half = m / 2;
    vector<pair<int, int>> b(1 << l_half);
    for (int mask = 0; mask < 1 << l_half; mask++) {
      int sum = 0;
      for (int bit = 0; bit < l_half; bit++) {
        if ((mask >> bit) & 1) {
          sum += step[bit];
        } else {
          sum -= step[bit];
        }
      }
      b[mask] = make_pair(sum, mask);
    }
    sort(b.begin(), b.end());
    int r_half = m - l_half;
    for (int mask = 0; mask < 1 << r_half; mask++) {
      int sum = 0;
      for (int bit = 0; bit < r_half; bit++) {
        if ((mask >> bit) & 1) {
          sum += step[bit + l_half];
        } else {
          sum -= step[bit + l_half];
        }
      }
      auto it = lower_bound(b.begin(), b.end(), make_pair(target - sum, -int(2e9)));
      if (it != b.end() && (*it).first == target - sum) {
        vector<int> res;
        for (int bit = 0; bit < l_half; bit++) {
          if (((*it).second >> bit) & 1) {
            res.emplace_back(1);
          } else {
            res.emplace_back(-1);
          }
        }
        for (int bit = 0; bit < r_half; bit++) {
          if ((mask >> bit) & 1) {
            res.emplace_back(1);
          } else {
            res.emplace_back(-1);
          }
        }
        return res;
      }
    }
    return {};
  };
  auto X = Get(dx, x);
  auto Y = Get(dy, y);
  debug(Y);
  debug(X);
  if ((int) X.size() == 0 || (int) Y.size() == 0) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  string s;
  int dir_x = 1;
  int dir_y = 1;
  vector<int> dir;
  for (int it = 0, xi = 0, yi = 0; it < n; it++) {
    if (it & 1) {
      // x
      if (dir_y == 1) {
        if (X[xi] == 1) {
          s += 'R';
        } else {
          s += 'L';
        }
      } else {
        if (X[xi] == 1) {
          s += 'L';
        } else {
          s += 'R';
        }
      }
      dir_x = X[xi];
      xi += 1;
    } else {
      // y
      if (dir_x == 1) {
        if (Y[yi] == 1) {
          s += 'L';
        } else {
          s += 'R';
        }
      } else {
        if (Y[yi] == 1) {
          s += 'R';
        } else {
          s += 'L';
        }
      }
      dir_y = Y[yi];
      yi += 1;
    }
  }
  cout << s << '\n';
  return 0;
}
