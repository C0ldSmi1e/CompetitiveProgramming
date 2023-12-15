/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-09 08:26:36
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1904/problem/B
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
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<int> res(n);
    debug(a);
    long long pref = 0;
    int i = 0;
    int j = 1;
    while (i < n) {
      pref += a[i].first;
      while (j < n && pref >= a[j].first) {
        pref += a[j].first;
        j += 1;
      }
      while (i < j) {
        res[a[i].second] = j - 1;
        i += 1;
      }
      j += 1;
    }
    for (auto& u : res) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
