/**
 * Author: C0ldSmi1e
 * Created Time: 02/06/2024 07:38:57 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1927/problem/B
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
    map<int, string> mp;
    mp[0] = string(26, '#');
    iota(mp[0].begin(), mp[0].end(), 'a');
    string s(n, '#');
    for (int i = 0; i < n; i++) {
      s[i] = mp[a[i]].back();
      mp[a[i] + 1] += mp[a[i]].back();
      mp[a[i]].pop_back();
    }
    cout << s << '\n';
  }
  return 0;
}
