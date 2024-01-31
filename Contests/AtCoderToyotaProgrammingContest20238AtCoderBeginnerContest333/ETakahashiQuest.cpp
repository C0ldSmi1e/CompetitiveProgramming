/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-16 16:12:46
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc333/tasks/abc333_e
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

  int n;
  cin >> n;
  vector<int> t(n);
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> x[i];
    --t[i];
    --x[i];
  }
  vector<bool> st(n);
  vector<int> b(n);
  for (int i = n - 1; i >= 0; i--) {
    if (t[i] == 1) {
      b[x[i]] += 1;
    } else {
      if (b[x[i]] > 0) {
        st[i] = true;
        b[x[i]] -= 1;
      }
    }
  }
  if (accumulate(b.begin(), b.end(), 0) > 0) {
    cout << "-1\n";
    return 0;
  }
  int mn = 0;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (t[i] == 0) {
      if (st[i]) {
        cur += 1;
      }
    } else {
      cur -= 1;
    }
    mn = max(mn, cur);
  }
  cout << mn << '\n';
  for (int i = 0; i < n; i++) {
    if (t[i] == 0) {
      cout << (st[i] ? "1 " : "0 ");
    }
  }
  cout << '\n';
  return 0;
}
