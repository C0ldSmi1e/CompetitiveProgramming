/**
 * Author: C0ldSmi1e
 * Created Time: 05/05/2024 04:24:01 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1968/problem/G2
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

// z[i] is the length of the longest common prefix
// between s and the suffix of s starting at i
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
    int sq = (int) sqrt(n);
    vector<int> b(n + 1);
    auto Get = [&](int len) -> int {
      int j = 0;
      int cnt = 0;
      while (j < n) {
        if (z[j] >= len) {
          j += len;
          cnt += 1;
          continue;
        }
        j += 1;
      }
      return cnt;
    };
    for (int i = 1; i <= sq; i++) {
      int l = 0, r = n;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (Get(mid) >= i) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      b[i] = r;
    }
    for (int len = 1; len <= sq; len++) {
      int cnt = Get(len);
      b[cnt] = max(b[cnt], len);
    }
    for (int i = n - 1; i >= 1; i--) {
      b[i] = max(b[i], b[i + 1]);
    }
    for (int i = x; i <= y; i++) {
      cout << b[i] << " \n"[i == y];
    }
  }
  return 0;
}
