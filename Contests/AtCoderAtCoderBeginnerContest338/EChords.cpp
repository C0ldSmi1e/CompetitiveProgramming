/**
 * Author: C0ldSmi1e
 * Created Time: 01/30/2024 03:09:15 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc338/tasks/abc338_e
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

  int n;
  cin >> n;
  vector<pair<int, int>> seg(n);
  for (auto& [l, r] : seg) {
    cin >> l >> r;
    --l;
    --r;
    if (l > r) {
      swap(l, r);
    }
  }
  sort(seg.begin(), seg.end());
  set<int> S;
  bool flag = false;
  for (auto& [l, r] : seg) {
    while ((int) S.size() > 0 && *S.begin() < l) {
      S.erase(S.begin());
    }
    if ((int) S.size() > 0 && *S.begin() < r) {
      flag = true;
    }
    S.insert(r);
  }
  cout << (flag ? "Yes\n" : "No\n");
  return 0;
}
