/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-07 06:42:14
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1894/problem/0
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

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << s.back() << '\n';
  }
  return 0;
}
