/**
 * Author: C0ldSmi1e
 * Created Time: 01/18/2024 06:39:47 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1922/problem/A
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
    string a, b, c;
    cin >> a >> b >> c;
    bool flag = false;
    for (int i = 0; i < n; i++) {
      flag |= (c[i] != a[i] && c[i] != b[i]);
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
