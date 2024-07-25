// time-limit: 1000
// problem-url: https://codeforces.com/contest/1937/problem/A
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

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int x = 1;
    while (x * 2 <= n) {
      x <<= 1;
    }
    cout << x << '\n';
  }
  return 0;
}
