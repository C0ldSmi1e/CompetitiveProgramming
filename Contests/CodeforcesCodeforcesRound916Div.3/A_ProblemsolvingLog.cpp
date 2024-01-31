/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-19 06:37:19
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1914/problem/A
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
    vector<int> cnt(26);
    for (auto& c : s) {
      cnt[(int) (c - 'A')] += 1;
    }
    int res = 0;
    for (char c = 'A'; c <= 'Z'; c++) {
      res += (int) (cnt[(int) (c - 'A')] >= (c - 'A' + 1));
    }
    cout << res << '\n';
  }
  return 0;
}
