/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-05 10:10:14
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc326/tasks/abc326_a
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  int x, y;
  cin >> x >> y;
  if (y - x >= 0 && y - x <= 2)  {
    cout << "Yes\n";
    return 0;
  }
  if (x - y >= 0 && x - y <= 3)  {
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";
  return 0;
}
