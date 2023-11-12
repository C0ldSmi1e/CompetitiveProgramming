/**
 * Author: C0ldSmi1e
 * Created Time: 2023-10-23 20:15:16
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc325/tasks/abc325_d
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

  int n;
  cin >> n;
  vector<pair<long long, long long>> a(n);
  for (int i = 0; i < n; i++) {
    long long x;
    long long y;
    cin >> x >> y;
    y += x;
    a[i] = make_pair(x, y);
  }
  sort(a.begin(), a.end());
  long long cur = 0;
  multiset<long long> S;
  int res = 0;
  int i = 0;
  while (!(i >= n && (int) S.size() == 0)) {
    while ((int) S.size() > 0 && *S.begin() < cur) {
      S.erase(S.begin());
    }
    if ((int) S.size() == 0) {
      cur = a[i].first;
    }
    while (i < n && a[i].first == cur) {
      S.insert(a[i].second);
      i += 1;
    }
    if ((int) S.size() > 0) {
      S.erase(S.begin());
      cur += 1;
      res += 1;
    }
  }
  cout << res << '\n';
  return 0;
}
