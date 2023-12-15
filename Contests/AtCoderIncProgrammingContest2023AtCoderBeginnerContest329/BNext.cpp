/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-18 22:27:20
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc329/tasks/abc329_b
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
  sort(a.begin(), a.end());
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] != a[n - 1]) {
      cout << a[i] << '\n';
      return 0;
    }
  }
  return 0;
}
