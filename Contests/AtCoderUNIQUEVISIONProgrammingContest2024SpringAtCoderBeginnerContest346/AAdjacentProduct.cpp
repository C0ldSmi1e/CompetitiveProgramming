/**
 * Author: C0ldSmi1e
 * Created Time: 03/27/2024 11:06:42 AM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc346/tasks/abc346_a
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
  for (auto& u : a) {
    cin >> u;
  }
  for (int i = 0; i < n - 1; i++) {
    cout << a[i] * a[i + 1] << ' ';
  }
  cout << '\n';
  return 0;
}
