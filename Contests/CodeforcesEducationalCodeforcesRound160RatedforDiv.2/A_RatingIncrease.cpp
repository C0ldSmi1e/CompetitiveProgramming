/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-18 06:36:34
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1913/problem/A
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
    int a = 0;
    int b = 0;
    for (int i = 1; i < (int) s.size(); i++) {
      if (s[i] != '0') {
        a = stoi(s.substr(0, i));
        b = stoi(s.substr(i));
        break;
      }
    }
    if (a < b) {
      cout << a << ' ' << b << '\n';
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}
