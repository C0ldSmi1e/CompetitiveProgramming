/**
 * Author: C0ldSmi1e
 * Created Time: 01/06/2024 08:32:24 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1919/problem/D
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
    if (*min_element(a.begin(), a.end()) != 0) {
      cout << "NO\n";
      continue;
    }
    vector<int> pre(n);
    vector<int> nxt(n);
    for (int i = 0; i < n; i++) {
      pre[i] = i - 1;
      nxt[i] = i + 1;
    }
    auto Check = [&](int i) -> bool {
      if (pre[i] >= 0 && pre[i] < n && a[pre[i]] + 1 == a[i]) {
        return true;
      }
      if (nxt[i] >= 0 && nxt[i] < n && a[nxt[i]] + 1 == a[i]) {
        return true;
      }
      return false;
    };
    priority_queue<pair<int, int>> heap;
    vector<bool> st(n);
    for (int i = 0; i < n; i++) {
      if (Check(i)) {
        st[i] = true;
        heap.push(make_pair(a[i], i));
      }
    }
    while ((int) heap.size() > 0) {
      auto [v, i] = heap.top();
      heap.pop();
      if (pre[i] >= 0 && pre[i] < n) {
        nxt[pre[i]] = nxt[i];
        if (!st[pre[i]] && Check(pre[i])) {
          st[pre[i]] = true;
          heap.push(make_pair(a[pre[i]], pre[i]));
        }
      }
      if (nxt[i] >= 0 && nxt[i] < n) {
        pre[nxt[i]] = pre[i];
        if (!st[nxt[i]] && Check(nxt[i])) {
          st[nxt[i]] = true;
          heap.push(make_pair(a[nxt[i]], nxt[i]));
        }
      }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (!st[i]) {
        cnt += 1;
      }
    }
    cout << (cnt == 1 ? "YES\n" : "NO\n");
  }
  return 0;
}
