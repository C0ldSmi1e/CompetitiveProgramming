/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-01 21:04:02
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1891/problem/E
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

  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    if (count(a.begin(), a.end(), 1) == n) {
      cout << n - min(k, n) << '\n';
      continue;
    }
    int tot = 0;
    for (int i = 0; i < n - 1; i++) {
      tot += (int) (gcd(a[i], a[i + 1]) == 1);
    }
    vector<int> seg;
    vector<bool> one;
    for (int i = 0; i < n; i++) {
      if (a[i] == 1) {
        int j = i;
        while (j < n && a[j] == 1) {
          j += 1;
        }
        seg.emplace_back(j - i);
        one.emplace_back(true);
        i = j - 1;
        continue;
      }
      int j = i + 1;
      while (j < n && a[j] != 1 && gcd(a[j], a[j - 1]) == 1) {
        j += 1;
      }
      seg.emplace_back(j - i);
      one.emplace_back(false);
      i = j - 1;
    }
    int m = (int) seg.size();
    int c1 = 0;
    for (int i = 0; i < m && k > 0; i++) {
      if (!one[i]) {
        int take = min(k, (seg[i] - 1) / 2);
        k -= take;
        tot -= 2 * take;
        c1 += (int) (seg[i] % 2 == 0);
      }
    }
    vector<int> b;
    for (int i = 1; i < m - 1; i++) {
      if (one[i]) {
        b.emplace_back(seg[i]);
      }
    }
    sort(b.begin(), b.end());
    for (auto& u : b) {
      if (k >= u) {
        tot -= u + 1;
        k -= u;
      } else {
        tot -= k;
        k = 0;
        break;
      }
    }
    if (one[0]) {
      c1 += seg[0];
    }
    if (m > 1 && one[m - 1]) {
      c1 += seg[m - 1];
    }
    int take = min(k, c1);
    tot -= take;
    cout << tot << '\n';
  }
  return 0;
}
