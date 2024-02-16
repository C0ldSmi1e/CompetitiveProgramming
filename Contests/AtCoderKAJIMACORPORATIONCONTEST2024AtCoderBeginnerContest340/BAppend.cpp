/**
 * Author: C0ldSmi1e
 * Created Time: 02/14/2024 10:48:00 AM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc340/tasks/abc340_b
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

  int q;
  cin >> q;
  vector<int> a;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      cin >> x;
      a.emplace_back(x);
    } else {
      int k;
      cin >> k;
      cout << a[(int) a.size() - k] << '\n';
    }
  }
  return 0;
}
