/**
 * Author: C0ldSmi1e
 * Created Time: 01/12/2024 02:21:13 PM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START116B/problems/ACCESS
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
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    bool flag = true;
    int cur = 0;
    for (auto& c : s) {
      if (c == '0') {
        cur -= 1;
        flag &= (cur >= 0);
      } else {
        cur = x;
      }
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
