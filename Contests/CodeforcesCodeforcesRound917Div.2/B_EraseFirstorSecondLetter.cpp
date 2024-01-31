/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-24 06:46:06
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1917/problem/B
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
    vector<bool> st(26);
    long long res = 0;
    for (int i = 0; i < n; i++) {
      if (!st[(int) (s[i] - 'a')]) {
        res += n - i;
        st[(int) (s[i] - 'a')] = true;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
