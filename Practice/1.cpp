/**
 * Author: C0ldSmi1e
 * Created Time: 02/08/2025 06:19:39 PM
**/

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
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    vector<int> b(n);
    for (auto& u : b) {
      cin >> u;
    }
    int ans = 0;
    auto Check = [&](int x) -> bool {
      map<int, int> mpa;
      for (auto& u : a) {
        mpa[u & x] += 1;
      }
      map<int, int> mpb;
      for (auto& u : b) {
        mpb[u & x] += 1;
      }
      bool flag = true;
      for (auto& [c, y] : mpa) {
        int z = (x ^ c);
        flag &= (mpb[z] == y);
      }
      return flag;
    };
    for (int bit = 30; bit >= 0; bit--) {
      if (Check(ans | (1 << bit))) {
        ans |= (1 << bit);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
