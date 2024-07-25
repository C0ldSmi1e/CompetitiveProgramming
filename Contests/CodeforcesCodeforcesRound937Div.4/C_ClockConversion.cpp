/**
 * Author: C0ldSmi1e
 * Created Time: 03/28/2024 07:52:45 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1950/problem/C
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
    int h = (int) (s[0] - '0') * 10 + (int) (s[1] - '0');
    int m = (int) (s[3] - '0') * 10 + (int) (s[4] - '0');
    int hh = h;
    if (h == 0) {
      hh = 12;
    }
    if (h > 12) {
      hh = h % 12;
    }
    if (hh < 10) {
      cout << 0;
    }
    cout << hh << ':';
    if (m < 10) {
      cout << 0;
    }
    cout << m << ' ';
    if (h >= 12) {
      cout << "PM\n";
    } else {
      cout << "AM\n";
    }
  }
  return 0;
}
