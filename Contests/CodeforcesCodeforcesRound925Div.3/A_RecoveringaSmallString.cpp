/**
 * Author: C0ldSmi1e
 * Created Time: 02/13/2024 06:40:25 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1931/problem/A
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
    string s = "";
    for (int i = 1; i <= 26 && s == ""; i++) {
      for (int j = 1; j <= 26 && s == ""; j++) {
        int k = n - i - j;
        if (k <= 26) {
          s += (char) ('a' + i - 1);
          s += (char) ('a' + j - 1);
          s += (char) ('a' + k - 1);
          break;
        }
      }
    }
    cout << s << '\n';
  }
  return 0;
}
