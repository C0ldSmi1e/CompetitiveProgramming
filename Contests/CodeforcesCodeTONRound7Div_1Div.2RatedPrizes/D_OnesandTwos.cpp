/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-25 10:53:04
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1896/problem/D
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
    set<int> S;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 1) {
        S.insert(i);
      }
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    while (q--) {
      int type;
      cin >> type;
      if (type == 1) {
        int s;
        cin >> s;
        if (sum < s) {
          cout << "NO\n";
          continue;
        }
        if (sum % 2 == s % 2) {
          cout << "YES\n";
          continue;
        }
        if ((int) S.size() == 0) {
          cout << "NO\n";
          continue;
        }
        int cnt = min(*S.begin(), n - *S.rbegin() - 1);
        if (sum - 2 * cnt >= s) {
          cout << "YES\n";
          continue;
        }
        cout << "NO\n";
      } else {
        int i, v;
        cin >> i >> v;
        --i;
        sum -= a[i];
        if (a[i] == 1) {
          S.erase(i);
        }
        a[i] = v;
        if (a[i] == 1) {
          S.insert(i);
        }
        sum += a[i];
      }
    }
  }
  return 0;
}
