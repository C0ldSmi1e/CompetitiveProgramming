/**
 * Author: C0ldSmi1e
 * Created Time: 08/30/2025 08:53:09 PM
**/

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

  int n;
  cin >> n;
  string s;
  cin >> s;
  auto Greater = [&](string& a, string& b) -> bool {
    if ((int) a.size() > (int) b.size()) {
      return true;
    }
    if ((int) a.size() < (int) b.size()) {
      return false;
    }
    for (int i = 0; i < (int) a.size(); i++) {
      if (a[i] == b[i]) {
        continue;
      }
      if (a[i] < b[i]) {
        return false;
      }
      return true;
    }
    return false;
  };
  auto Add = [&](string a, string b) -> string {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string c;
    for (int i = 0, j = 0, t = 0; ; i++, j++) {
      if (i >= (int) a.size() && j >= (int) b.size() && t == 0) {
        break;
      }
      if (i < (int) a.size()) {
        t += (int) (a[i] - '0');
      }
      if (j < (int) b.size()) {
        t += (int) (b[j] - '0');
      }
      c += (char) (t % 10 + '0');
      t /= 10;
    }
    reverse(c.begin(), c.end());
    return c;
  };
  const string INF = string((int) 1e6, '9');
  auto Find = [&](int x) -> string {
    if (s[x] != '0') {
      return Add(s.substr(0, x), s.substr(x));
    }
    int l = x;
    while (l >= 0 && s[l] == '0') {
      --l;
    }
    string ls;
    if (l <= 0) {
      ls = INF;
    } else {
      ls = Add(s.substr(0, l), s.substr(l));
    }
    int r = x;
    while (r < n && s[r] == '0') {
      ++r;
    }
    string rs;
    if (r >= n) {
      rs = INF;
    } else {
      rs = Add(s.substr(0, r), s.substr(r));
    }
    if (Greater(ls, rs)) {
      return rs;
    }
    return ls;
  };
  string ans = INF;
  for (int i = max(0, n / 2 - 5); i < min(n, n / 2 + 5); i++) {
    auto t = Find(i);
    if (Greater(ans, t)) {
      ans = t;
    }
  }
  cout << ans << '\n';
  return 0;
}
