/**
 * Author: C0ldSmi1e
 * Created Time: 01/27/2024 06:50:38 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1925/problem/A
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
    int n, k;
    cin >> n >> k;
    string s, t;
    for (int i = 0; i < k; i++) {
      t += (char) (i + 'a');
    }
    for (int i = 0; i < n; i++) {
      s += t;
    }
    cout << s << '\n';
  }
  return 0;
}
