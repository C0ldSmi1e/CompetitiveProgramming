/**
 * Author: C0ldSmi1e
 * Created Time: 03/10/2025 07:52:34 AM
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

  int k;
  cin >> k;
  if (k == 0) {
    cout << "1 1\n1\n";
    return 0;
  }
  auto Get = [&](int x) -> string {
    string s;
    do {
      s += (char) ('0' + x % 2);
      x /= 2;
    } while (x > 0);
    return s;
  };
  string s = Get(k);
  s += '1';
  reverse(s.begin(), s.end());
  string t;
  t += '1';
  t += string((int) s.size() - 1, '0');
  int x = 0, y = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    x = x * 2 + (int) (s[i] - '0');
    y = y * 2 + (int) (t[i] - '0');
  }
  cout << "2 3\n";
  cout << x << ' ' << y << " 0" << '\n';
  cout << k << ' ' << x << ' ' << k << '\n';
  return 0;
}
