/**
 * Author: C0ldSmi1e
 * Created Time: 03/14/2024 03:53:13 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc344/tasks/abc344_b
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

  vector<int> a;
  int x;
  while (cin >> x) {
    a.emplace_back(x);
  }
  reverse(a.begin(), a.end());
  for (auto& u : a) {
    cout << u << '\n';
  }
  return 0;
}
