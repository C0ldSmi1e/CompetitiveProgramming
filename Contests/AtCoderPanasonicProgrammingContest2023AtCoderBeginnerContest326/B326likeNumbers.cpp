/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-05 10:15:51
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc326/tasks/abc326_b
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

  auto Check = [&](int x) {
    int a = x / 100;
    int b = (x / 10) % 10;
    int c = x % 10;
    return a * b == c;
  };
  int n;
  cin >> n;
  while (!Check(n)) {
    n += 1;
  }
  cout << n << '\n';
  return 0;
}
