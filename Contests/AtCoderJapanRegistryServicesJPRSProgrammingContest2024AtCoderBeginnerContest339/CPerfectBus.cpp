/**
 * Author: C0ldSmi1e
 * Created Time: 02/05/2024 03:13:22 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc339/tasks/abc339_c
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
  long long pref = 0;
  long long x = 0;
  for (auto& u : a) {
    cin >> u;
    pref += u;
    x = min(x, pref);
  }
  x = abs(x);
  cout << x + accumulate(a.begin(), a.end(), 0ll) << '\n';
  return 0;
}
