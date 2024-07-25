// time-limit: 2000
// problem-url: https://codeforces.com/contest/1948/problem/A
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
    if (n & 1) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 0, j = 0; i < n / 2; i++, j++) {
      cout << (char) ('A' + j);
      cout << (char) ('A' + j);
    }
    cout << '\n';
  }
  return 0;
}
