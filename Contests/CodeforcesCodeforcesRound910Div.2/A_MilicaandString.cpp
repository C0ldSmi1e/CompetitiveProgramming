/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-20 19:49:29
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1898/problem/A
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int i = n - 1;
    int cur = 0;
    while (i >= 0) {
      if (cur == k) {
        break;
      }
      if (s[i] == 'B') {
        cur += 1;
      }
      i -= 1;
    }
    if (cur >= k) {
      if (count(s.begin(), s.begin() + i + 1, 'B') > 0) {
        cout << "1\n" << i + 1 << " A\n";
      } else {
        cout << "0\n";
      }
      continue;
    }
    i = 0;
    while (i < n) {
      if (s[i] == 'A') {
        cur += 1;
      }
      if (cur >= k) {
        break;
      }
      i += 1;
    }
    cout << "1\n";
    cout << i + 1 << " B\n";
  }
  return 0;
}
