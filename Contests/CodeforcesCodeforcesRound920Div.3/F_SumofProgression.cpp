/**
 * Author: C0ldSmi1e
 * Created Time: 01/15/2024 08:28:00 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1921/problem/F
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    map<int, vector<array<int, 3>>> mp;
    for (int i = 0; i < q; i++) {
      int s, d, k;
      cin >> s >> d >> k;
      int l = s, r = s + (k - 1) * d;
      l -= 1, r -= 1;
      mp[d].push_back({i, l, r});
    }
    vector<long long> res(q);
    for (auto& [d, query] : mp) {
      map<int, vector<array<int, 3>>> mpp;
      for (auto& [id, l, r] : query) {
        mpp[l % d].push_back({id, l / d, r / d});
      }
      debug(d, query);
      debug(mpp);
      for (auto& [t, queryy] : mpp) {
        vector<int> b;
        for (int i = t; i < n; i += d) {
          b.emplace_back(a[i]);
        }
        int m = (int) b.size();
        vector<long long> pref1(m + 1);
        vector<long long> pref2(m + 1);
        for (int i = 0; i < m; i++) {
          pref1[i + 1] = pref1[i] + b[i];
          pref2[i + 1] = pref2[i] + 1ll * b[i] * (i + 1);
        }
        for (auto& [id, ll, rr] : queryy) {
          res[id] = pref2[rr + 1] - pref2[ll];
          res[id] -= (pref1[rr + 1] - pref1[ll]) * ll;
        }
      }
    }
    for (auto& u : res) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
