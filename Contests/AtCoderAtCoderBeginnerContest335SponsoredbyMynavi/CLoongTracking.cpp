/**
 * Author: C0ldSmi1e
 * Created Time: 01/07/2024 11:30:51 AM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc335/tasks/abc335_c
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

  int n, q;
  cin >> n >> q;
  deque<pair<int, int>> p;
  for (int i = 1; i <= n; i++) {
    p.push_back(make_pair(i, 0));
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      char c;
      cin >> c;
      if (c == 'U') {
        p.push_front(make_pair(p.front().first, p.front().second + 1));
        p.pop_back();
      }
      if (c == 'D') {
        p.push_front(make_pair(p.front().first, p.front().second - 1));
        p.pop_back();
      }
      if (c == 'L') {
        p.push_front(make_pair(p.front().first - 1, p.front().second));
        p.pop_back();
      }
      if (c == 'R') {
        p.push_front(make_pair(p.front().first + 1, p.front().second));
        p.pop_back();
      }
    } else {
      int i;
      cin >> i;
      --i;
      cout << p[i].first << ' ' << p[i].second << '\n';
    }
  }
  return 0;
}
