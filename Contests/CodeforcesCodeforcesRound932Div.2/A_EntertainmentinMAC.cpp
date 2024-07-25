/**
 * Author: C0ldSmi1e
 * Created Time: 03/08/2024 08:38:21 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1935/problem/A
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
    string t = s;
    reverse(t.begin(), t.end());
    cout << min({s, s + t, t + s}) << '\n';
  }
  return 0;
}
