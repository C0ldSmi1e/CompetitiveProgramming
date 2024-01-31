/**
 * Author: C0ldSmi1e
 * Created Time: 01/18/2024 02:27:27 PM
**/

// time-limit: 2000
// problem-url: 
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
    long long x;
    cin >> x;
    int l = 0, r = 0;
    vector<int> a;
    auto Dfs = [&](auto& self, long long y) -> void {
      if (y == 1) {
        return;
      }
      if (y & 1) {
        self(self, y - 1);
        --l;
        a.emplace_back(l);
      } else {
        self(self, y / 2);
        ++r;
        a.emplace_back(r);
      }
    };
    Dfs(Dfs, x);
    cout << (int) a.size() << '\n';
    for (auto& u : a) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
