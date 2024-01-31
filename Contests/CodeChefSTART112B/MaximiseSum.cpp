/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-17 11:46:56
**/

// time-limit: 1500
// problem-url: https://www.codechef.com/START112B/problems/MAXSUMOPS
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
    long long k;
    cin >> k;
    multiset<long long> odd, even;
    int mx = 0;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      mx += Get(x);
      if (x & 1) {
        odd.emplace(x);
      } else {
        even.emplace(x);
      }
    }
    if (k > mx) {
      cout << "0\n";
      continue;
    }
    while (k--) {
      if ((int) odd.size() > 0) {
        int x = *odd.begin();
        odd.erase(odd.begin());
        even.emplace(x + 1);
      } else {
        int x = *even.begin();
        even.erase(even.begin());
        x /= 2;
        if (x & 1) {
          odd.emplace(x);
        } else {
          even.emplace(x);
        }
      }
    }
    long long sum = accumulate(odd.begin(), odd.end(), 0ll);
    sum += accumulate(even.begin(), even.end(), 0ll);
    cout << sum << '\n';
  }
  return 0;
}
