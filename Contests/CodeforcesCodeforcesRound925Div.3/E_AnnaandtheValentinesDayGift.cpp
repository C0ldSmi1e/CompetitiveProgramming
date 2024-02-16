/**
 * Author: C0ldSmi1e
 * Created Time: 02/13/2024 07:14:23 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1931/problem/E
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
    vector<string> g(n);
    int sum = 0;
    vector<int> zeros;
    for (auto& s : g) {
      cin >> s;
      sum += (int) s.size();
      int cnt = 0;
      for (int i = (int) s.size() - 1; s[i] == '0'; i--) {
        cnt += 1;
      }
      if (cnt > 0) {
        zeros.emplace_back(cnt);
      }
    }
    sort(zeros.rbegin(), zeros.rend());
    for (int i = 0; i < (int) zeros.size(); i += 2) {
      sum -= zeros[i];
    }
    cout << (sum >= m + 1 ? "Sasha\n" : "Anna\n");
  }
  return 0;
}
