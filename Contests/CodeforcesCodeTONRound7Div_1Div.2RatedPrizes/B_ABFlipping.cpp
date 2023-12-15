/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-25 06:57:45
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1896/problem/B
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
    int res = 0;
    vector<bool> st(n);
    for (int i = n - 2; i >= 0; i--) {
      if (s[i] == 'A' && s[i + 1] == 'B') {
        st[i] = true;
        res += 1;
        swap(s[i], s[i + 1]);
      }
    }
    for (int i = 0; i < n - 1; i++) {
      if (!st[i] && s[i] == 'A' && s[i + 1] == 'B') {
        res += 1;
        swap(s[i], s[i + 1]);
      }
    }
    cout << res << '\n';
  }
  return 0;
}
