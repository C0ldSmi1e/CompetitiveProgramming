/**
 * Author: C0ldSmi1e
 * Created Time: 05/05/2024 03:49:29 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1968/problem/G1
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
vector<int> ZFunction(int n, const T &s) {
  vector<int> z(n, n);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    z[i] = (i > r ? 0 : min(r - i + 1, z[i - l]));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}

template <typename T>
vector<int> ZFunction(const T &s) {
  return ZFunction((int) s.size(), s);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int T;
  cin >> T;
  while (T--) {
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    auto z = ZFunction(s);
    int l = 0, r = n;
    auto Check = [&](int len) -> bool {
      int cnt = 0;
      int i = 0;
      while (i < n) {
        if (z[i] >= len) {
          i += len;
          cnt += 1;
          continue;
        }
        i += 1;
      }
      return cnt >= x;
    };
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (Check(mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    cout << r << '\n';
  }
  return 0;
}
