/**
 * Author: C0ldSmi1e
 * Created Time: 01/20/2024 05:52:48 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc337/tasks/abc337_c
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
  vector<int> a(n);
  vector<int> b(n, -1);
  int p = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == -1) {
      p = i;
    } else {
      b[a[i] - 1] = i;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << p + 1 << " \n"[i == n - 1];
    p = b[p];
  }
  return 0;
}
