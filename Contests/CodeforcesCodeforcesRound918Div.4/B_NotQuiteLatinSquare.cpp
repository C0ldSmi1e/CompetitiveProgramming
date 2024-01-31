/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-28 06:38:17
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1915/problem/B
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
    vector<string> g(3);
    char res;
    for (auto& s : g) {
      cin >> s;
      bool a = false;
      bool b = false;
      bool c = false;
      if (s.find('?') != string::npos) {
        for (auto& u : s) {
          a |= u == 'A';
          b |= u == 'B';
          c |= u == 'C';
        }
        if (!a) {
          res = 'A';
        }
        if (!b) {
          res = 'B';
        }
        if (!c) {
          res = 'C';
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}
