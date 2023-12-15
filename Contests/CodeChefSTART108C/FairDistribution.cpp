/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-15 12:22:36
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START108C/problems/FAIR_DISTRIB
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
    string s;
    cin >> s;
    vector<vector<int>> suff(n, vector<int>(2));
    for (int i = n - 1; i >= 0; i--) {
      suff[i][(int) (s[i] - '0')] += 1;
      if (i + 1 < n) {
        suff[i][0] += suff[i + 1][0];
        suff[i][1] += suff[i + 1][1];
      }
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
      flag &= abs(suff[i][0] - suff[i][1]) < 2;
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
