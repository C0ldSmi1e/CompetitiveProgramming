/**
 * Author: C0ldSmi1e
 * Created Time: 03/07/2024 08:56:55 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc343/tasks/abc343_c
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

  string ans;
  long long n;
  cin >> n;
  for (long long i = 1; ; i++) {
    long long x = i * i * i;
    if (x > n) {
      break;
    }
    string s = to_string(x);
    string t = s;
    reverse(t.begin(), t.end());
    if (s == t) {
      ans = s;
    }
  }
  cout << ans << '\n';
  return 0;
}
