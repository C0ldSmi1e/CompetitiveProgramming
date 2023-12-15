/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-22 07:17:59
**/

// time-limit: 2000
// problem-url: https://www.codechef.com/START109B/problems/ASH57
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
    vector<int> ca(n);
    for (auto& u : ca) {
      cin >> u;
    }
    vector<int> b(n);
    for (auto& u : b) {
      cin >> u;
    }
    vector<bool> st(2 * n + 5);
    vector<int> cb(n);
    for (auto& u : cb) {
      cin >> u;
      st[u] = true;
    }
    vector<multiset<int>> S(2 * n + 5);
    for (int i = 0; i < n; i++) {
      S[ca[i]].insert(a[i]);
      S[cb[i]].insert(b[i]);
    }
    int last = 0;
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (st[ca[i]]) {
        auto it = S[ca[i]].lower_bound(last);
        if (it == S[ca[i]].end()) {
          flag = false;
          break;
        }
        last = *it;
        S[ca[i]].erase(it);
      } else {
        if (a[i] < last) {
          flag = false;
          break;
        }
        last = a[i];
      }
    }
    cout << (flag ? "Yes\n" : "No\n");
  }
  return 0;
}
