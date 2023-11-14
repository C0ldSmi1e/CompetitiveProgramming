/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-12 11:33:25
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc328/tasks/abc328_b
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

  int n;
  cin >> n;
  int res = 0;
  for (int i = 1; i <= n; i++) {
    string t = to_string(i);
    int d;
    cin >> d;
    while (d > 0) {
      string s = t + to_string(d);
      bool flag = true;
      for (int j = 1; j < (int) s.size(); j++) {
        flag &= (s[j] == s[j - 1]);
      }
      if (flag) {
        res += 1;
      }
      d -= 1;
    }
  }
  cout << res << '\n';
  return 0;
}
