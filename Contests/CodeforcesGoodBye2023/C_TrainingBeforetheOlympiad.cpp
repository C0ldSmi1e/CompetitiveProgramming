/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-30 07:22:16
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1916/problem/C
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
    int odd = 0;
    vector<long long> res(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] & 1) {
        odd += 1;
      } else {
      }
      if (i == 0) {
        sum += a[i];
        res[i] = sum;
        continue;
      }
      sum += a[i];
      // tot: i+1
      // M (i+2)/2, O (i+1)-(i+2)/2
      long long take = min((i + 1) - (i + 2) / 2, odd / 3 + (int) (odd % 3 == 1));
      res[i] = sum - take;
    }
    for (auto& u : res) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
