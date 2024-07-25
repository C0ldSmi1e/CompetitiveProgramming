/**
 * Author: C0ldSmi1e
 * Created Time: 03/06/2024 02:37:58 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc340/tasks/abc340_f
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

inline long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1; y = 0;
    return a;
  }
  long long d = exgcd(b, a % b, y, x);
  y -= (a / b) * x;
  return d;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  long long x, y;
  cin >> x >> y;
  long long g = gcd(x, y);
  if (g > 2) {
    cout << "-1\n";
    return 0;
  }
  long long a = 0, b = 0;
  exgcd(x, y, b, a);
  debug(a, y, b, x);
  // bx + ay == g
  if (g == 1) {
    a *= 2;
    b *= 2;
  }
  cout << a << ' ' << -b << '\n';
  return 0;
}
