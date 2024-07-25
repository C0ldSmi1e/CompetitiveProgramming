/**
 * Author: C0ldSmi1e
 * Created Time: 03/16/2024 07:40:49 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1944/problem/B
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
    int k;
    cin >> k;
    k *= 2;
    vector<int> a(2 * n);
    for (auto& u : a) {
      cin >> u;
    }
    set<int> Sl, Tl;
    for (int i = 0; i < n; i++) {
      if (Sl.count(a[i])) {
        Tl.insert(a[i]);
        Sl.erase(a[i]);
        continue;
      }
      Sl.insert(a[i]);
    }
    set<int> Sr, Tr;
    for (int i = n; i < 2 * n; i++) {
      if (Sr.count(a[i])) {
        Tr.insert(a[i]);
        Sr.erase(a[i]);
        continue;
      }
      Sr.insert(a[i]);
    }
    vector<int> b, c;
    while (k > 0 && (int) Tl.size() > 0) {
      b.emplace_back(*Tl.begin());
      b.emplace_back(*Tl.begin());
      Tl.erase(Tl.begin());
      c.emplace_back(*Tr.begin());
      c.emplace_back(*Tr.begin());
      Tr.erase(Tr.begin());
      k -= 2;
    }
    while (k > 0 && (int) Sl.size()) {
      b.emplace_back(*Sl.begin());
      c.emplace_back(*Sl.begin());
      Sl.erase(Sl.begin());
      k -= 1;
    }
    for (auto& u : b) {
      cout << u << ' ';
    }
    cout << '\n';
    for (auto& u : c) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
