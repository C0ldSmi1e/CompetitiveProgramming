/**
 * Author: C0ldSmi1e
 * Created Time: 02/01/2024 09:10:18 PM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START119A/problems/ADVITIYA5
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
    vector<vector<int>> cand(2);
    for (int i = 1; i <= n; i++) {
      cand[i & 1].emplace_back(i);
    }
    vector<int> res;
    res.emplace_back(cand[1].back());
    cand[1].pop_back();
    int last = 1;
    while (k > 1) {
      last ^= 1;
      res.emplace_back(cand[last].back());
      cand[last].pop_back();
      k -= 1;
    }
    while ((int) cand[last].size() > 0) {
      res.emplace_back(cand[last].back());
      cand[last].pop_back();
    }
    while ((int) cand[last ^ 1].size() > 0) {
      res.emplace_back(cand[last ^ 1].back());
      cand[last ^ 1].pop_back();
    }
    for (auto& u : res) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
