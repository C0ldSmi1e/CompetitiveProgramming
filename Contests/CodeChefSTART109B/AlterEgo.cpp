/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-22 06:56:18
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START109B/problems/ALT
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
    vector<int> odd;
    vector<int> even;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x & 1) {
        odd.emplace_back(x);
      } else {
        even.emplace_back(x);
      }
    }
    if (((int) odd.size()) & 1) {
      cout << "-1\n";
      continue;
    }
    if (((int) even.size()) & 1) {
      cout << "-1\n";
      continue;
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    vector<int> res(n);
    int ptr = 0;
    auto Get = [&](vector<int>& a) -> void {
      int m = (int) a.size();
      assert(m % 2 == 0);
      for (int i = 0; i < m / 2; i++) {
        int x = a[i];
        int y = a[i + m / 2];
        assert(x <= y);
        res[ptr] = (y - x) / 2;
        res[ptr + n / 2] = y - (y - x) / 2;
        ptr += 1;
      }
    };
    Get(odd);
    Get(even);
    assert(ptr == n / 2);
    for (auto& u : res) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
