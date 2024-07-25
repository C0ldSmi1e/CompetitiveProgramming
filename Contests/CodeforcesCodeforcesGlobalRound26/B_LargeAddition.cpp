/**
 * Author: C0ldSmi1e
 * Created Time: 06/10/2024 03:50:27 PM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1984/problem/B
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
    int n = (int) s.size();
    bool flag = s[0] == '1';
    for (int i = n - 1, t = 0; i >= 0; i--) {
      int c = (((int) (s[i] - '0') - t) + 10) % 10;
      flag &= c != 9;
      t = 1;
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
