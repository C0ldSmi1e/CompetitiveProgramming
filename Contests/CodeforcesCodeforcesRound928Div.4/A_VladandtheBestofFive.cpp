// time-limit: 1000
// problem-url: https://codeforces.com/contest/1926/problem/A
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
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (auto& c : s) {
      if (c == 'A') {
        a += 1;
      } else {
        b += 1;
      }
    }
    cout << (a > b ? 'A' : 'B') << '\n';
  }
  return 0;
}
