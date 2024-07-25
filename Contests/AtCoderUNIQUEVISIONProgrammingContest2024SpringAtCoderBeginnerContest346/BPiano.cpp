/**
 * Author: C0ldSmi1e
 * Created Time: 03/27/2024 11:21:41 AM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc346/tasks/abc346_b
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

  int w, b;
  cin >> w >> b;
  string s = "wbwbwwbwbwbw";
  while ((int) s.size() < 1000000) {
    s += s;
  }
  for (int i = w + b - 1; i < (int) s.size(); i++) {
    string t = s.substr(i - (w + b - 1), w + b);
    if (count(t.begin(), t.end(), 'w') == w) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}
