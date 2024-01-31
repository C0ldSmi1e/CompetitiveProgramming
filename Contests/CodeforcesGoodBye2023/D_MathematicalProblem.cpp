/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-30 07:35:37
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1916/problem/D
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

  //map<multiset<int>, vector<int>> mp;
  //for (int i = 1000000; i <= 9999999; i++) {
  //  if ((int) sqrt(i) * (int) sqrt(i) == i) {
  //    multiset<int> S;
  //    int x = i;
  //    while (x > 0) {
  //      S.insert(x % 10);
  //      x /= 10;
  //    }
  //    mp[S].emplace_back(i);
  //  }
  //}
  //for (auto& [S, arr] : mp) {
  //  debug(S, arr);
  //}
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "1\n";
      continue;
    }
    vector<string> g{"169", "196", "961"};
    // add n-3 0s
    while ((int) g.size() < n) {
      for (auto& s : g) {
        s += "00";
      }
      int m = (int) g[0].size() / 2 - 1;
      g.emplace_back("1" + string(m, '0') + "6" + string(m, '0') + "9");
      g.emplace_back("9" + string(m, '0') + "6" + string(m, '0') + "1");
    }
    for (auto& s : g) {
      cout << s << '\n';
    }
  }
  return 0;
}
