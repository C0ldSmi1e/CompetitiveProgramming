/**
 * Author: C0ldSmi1e
 * Created Time: 03/27/2024 10:01:43 PM
**/

// time-limit: 3000
// problem-url: https://atcoder.jp/contests/abc346/tasks/abc346_g
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
    --u;
  }
  return 0;
}
