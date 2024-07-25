/**
 * Author: C0ldSmi1e
 * Created Time: 06/23/2024 08:01:32 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1986/problem/C
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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> idx(m);
    for (auto& u : idx) {
      cin >> u;
      --u;
    }
    string t;
    cin >> t;
    sort(t.begin(), t.end());
    sort(idx.begin(), idx.end());
    for (int i = 0, k = 0; i < m; i++) {
      int j = i;
      while (j < m && idx[i] == idx[j]) {
        j += 1;
      }
      s[idx[i]] = t[k];
      k += 1;
      i = j - 1;
    }
    cout << s << '\n';
  }
  return 0;
}
