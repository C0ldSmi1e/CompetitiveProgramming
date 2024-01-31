/**
 * Author: C0ldSmi1e
 * Created Time: 01/06/2024 06:40:59 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1919/problem/B
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
    string stk;
    for (auto& c : s) {
      if ((int) stk.size() == 0) {
        stk += c;
        continue;
      }
      if (c != stk.back()) {
        stk.pop_back();
      } else {
        stk += c;
      }
    }
    cout << (int) stk.size() << '\n';
  }
  return 0;
}
