// time-limit: 2000
// problem-url: https://codeforces.com/contest/1902/problem/A
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
    string s;
    cin >> s;
    cout << (count(s.begin(), s.end(), '0') > 0 ? "YES\n" : "NO\n");
  }
  return 0;
}
