/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-08 06:34:11
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START107B/problems/PASCRO
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int win = 0;
    int lose = 0;
    int draw = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        draw += 1;
      }
      if (a[i] == 'R' && b[i] == 'S') {
        win += 1;
      }
      if (a[i] == 'S' && b[i] == 'P') {
        win += 1;
      }
      if (a[i] == 'P' && b[i] == 'R') {
        win += 1;
      }
    }
    lose = n - win - draw;
    if (win > lose) {
      cout << "0\n";
      continue;
    }
    int d = lose - win;
    int take = min(d / 2 + 1, lose);
    int res = take;
    win += take;
    lose -= take;
    if (win <= lose) {
      take = min(lose - win + 1, draw);
      res += take;
    }
    cout << res << '\n';
  }
  return 0;
}
