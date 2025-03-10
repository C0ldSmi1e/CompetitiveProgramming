/**
 * Author: C0ldSmi1e
 * Created Time: 03/10/2025 06:56:27 AM
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
    int n, m, q;
    cin >> n >> m >> q;
    string s;
    cin >> s;
    vector<pair<long long, long long>> add;
    vector<long long> len{n};
    for (int i = 0; i < m; i++) {
      long long l, r;
      cin >> l >> r;
      --l;
      --r;
      add.emplace_back(l, r);
      len.emplace_back(len.back() + r - l + 1);
    }
    while (q--) {
      long long k;
      cin >> k;
      k--;
      while (true) {
        auto it = lower_bound(len.begin(), len.end(), k + 1);
        if (it == len.begin()) {
          cout << s[k] << '\n';
          break;
        }
        int i = (int) (it - len.begin());
        long long p = k + 1 - len[i - 1];
        k = add[i - 1].first + p - 1;
      }
    }
  }
  return 0;
}
