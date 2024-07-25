/**
 * Author: C0ldSmi1e
 * Created Time: 02/26/2024 04:12:44 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1932/problem/E
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
    string s;
    cin >> s;
    vector<int> sum(n);
    for (int i = 0; i < n; i++) {
      sum[i] = (int) (s[i] - '0');
      if (i > 0) {
        sum[i] += sum[i - 1];
      }
    }
    reverse(sum.begin(), sum.end());
    vector<int> ans;
    for (int i = 0, t = 0; t > 0 || i < (int) sum.size(); i++) {
      if (i < (int) sum.size()) {
        t += sum[i];
      }
      ans.emplace_back(t % 10);
      t /= 10;
    }
    while ((int) ans.size() > 1 && ans.back() == 0) {
      ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    for (auto& u : ans) {
      cout << u;
    }
    cout << '\n';
  }
  return 0;
}
