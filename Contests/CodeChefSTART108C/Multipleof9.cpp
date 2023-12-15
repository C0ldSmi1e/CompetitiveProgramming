/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-15 07:56:24
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START108C/problems/MULT9
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  auto Add = [&](string& a, string& b) -> void {
    int t = 0;
    for (int i = 0; i < max((int) a.size(), (int) b.size()); i++) {
      if (i < (int) a.size()) {
        t += (int) (a[i] - '0');
      }
      if (i < (int) b.size()) {
        t += (int) (b[i] - '0');
      }
      if (i < (int) a.size()) {
        a[i] = char(t % 10 + '0');
      } else {
        a += char(t % 10 + '0');
      }
      t /= 10;
    }
    while (t) {
      a += char(t % 10 + '0');
      t /= 10;
    }
  };
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sum = 0;
    for (auto& u : s) {
      if (u != '?') {
        sum = (sum + (int) (u - '0')) % 9;
      }
    }
    int c = 0;
    for (int i = 1; i < n; i++) {
      c += (s[i] == '?');
    }
    vector<string> cnt(9, "0");
    vector<string> p9(9, string(c, '1'));
    if (c == 0) {
      for (int i = 0; i < 9; i++) {
        p9[i] = "0";
      }
    }
    p9[0][0] += 1;
    if (s[0] == '?') {
      for (int x = 1; x <= 9; x++) {
        Add(cnt[0], p9[(9 - (sum + x) % 9) % 9]);
      }
    } else {
      cnt[0] = p9[(9 - sum % 9) % 9];
    }
    reverse(cnt[0].begin(), cnt[0].end());
    cout << cnt[0] << '\n';
  }
  return 0;
}
