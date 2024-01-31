/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-20 06:35:36
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START113B/problems/MAXSCORE7
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
    vector<int> c(2);
    for (int i = 0; i < 2; i++) {
      c[i] = count(a.begin(), a.end(), i);
    }
    cout << min(c[0], c[1]) << '\n';
  }
  return 0;
}
