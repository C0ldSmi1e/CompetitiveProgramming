/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-22 07:35:13
**/

// time-limit: 2000
// problem-url: https://www.codechef.com/START109B/problems/CLARR
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
    int n, d;
    cin >> n >> d;
    vector<long long> b(n);
    for (auto& u : b) {
      cin >> u;
    }
    vector<long long> c(n);
    for (auto& u : c) {
      cin >> u;
    }
    if (b[0] != c[0]) {
      cout << "NO\n";
      continue;
    }
    vector<long long> a(n, -(long long) 1e18);
    a[0] = b[0];
    bool flag = true;
    for (int i = 1; i < n; i++) {
      flag &= b[i] >= b[i - 1];
      flag &= c[i] <= c[i - 1];
    }
    for (int i = 0; flag && i < n; i++) {
      int j = i + 1;
      while (j < n && b[j] == b[i] && c[j] == c[i]) {
        j += 1;
      }
      if (j >= n) {
        for (int k = i + 1; k < n; k++) {
          a[k] = a[k - 1];
        }
        break;
      }
      if (b[j] != b[i] && c[j] != c[i]) {
        flag = false;
        break;
      }
      long long nxt = (b[j] != b[i] ? b[j] : c[j]);
      for (int k = i + 1; k <= j; k++) {
        if (b[j] != b[i]) {
          a[k] = min(a[k - 1] + d, b[k]);
        } else {
          a[k] = max(a[k - 1] - d, c[k]);
        }
      }
      if (a[j] != nxt) {
        flag = false;
        break;
      }
      i = j - 1;
    }
    if (!flag) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      cout << a[i] << " \n"[i == n - 1];
      if (i > 0) {
        assert(a[i] - a[i - 1] <= d);
      }
    }
  }
  return 0;
}

