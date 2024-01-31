/**
 * Author: C0ldSmi1e
 * Created Time: 01/14/2024 02:02:28 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc336/tasks/abc336_c
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

  long long n;
  cin >> n;
  n -= 1;
  int base = 5;
  string s;
  do {
    s += (char) ('0' + (n % base) * 2);
    n /= base;
  } while (n > 0);
  reverse(s.begin(), s.end());
  cout << s << '\n';
  return 0;
}
