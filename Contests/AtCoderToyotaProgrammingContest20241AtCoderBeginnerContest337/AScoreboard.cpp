/**
 * Author: C0ldSmi1e
 * Created Time: 01/20/2024 05:11:38 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc337/tasks/abc337_a
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
  int a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a += x;
    b += y;
  }
  if (a == b) {
    cout << "Draw\n";
    return 0;
  }
  cout << (a > b ? "Takahashi\n" : "Aoki\n");
  return 0;
}
