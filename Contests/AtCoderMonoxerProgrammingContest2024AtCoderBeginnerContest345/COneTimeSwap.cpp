/**
 * Author: C0ldSmi1e
 * Created Time: 03/16/2024 10:05:17 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc345/tasks/abc345_c
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

  string s;
  cin >> s;
  int n = (int) s.size();
  vector<int> cnt(26);
  for (int i = 0; i < n; i++) {
    cnt[(int) (s[i] - 'a')] += 1;
  }
  long long ans = (int) (*max_element(cnt.begin(), cnt.end()) > 1);
  for (int i = 0; i < n; i++) {
    cnt[(int) (s[i] - 'a')] -= 1;
    ans += n - 1 - i - (int) (cnt[(int) (s[i] - 'a')]);
  }
  cout << ans << '\n';
  return 0;
}
