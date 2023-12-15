/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-03 08:04:31
**/

// time-limit: 6500
// problem-url: https://codeforces.com/contest/1902/problem/E
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

const int N = 1000010;
int son[N][26];
int idx;
int cnt[26 * N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  auto Insert = [&](string& s) -> void {
    int p = 0;
    for (auto& u : s) {
      if (son[p][(int) (u - 'a')] == 0) {
        son[p][(int) (u - 'a')] = ++idx;
      }
      p = son[p][(int) (u - 'a')];
      cnt[p] += 1;
    }
  };
  int n;
  cin >> n;
  long long tot = 0;
  vector<string> g(n);
  for (auto& s : g) {
    cin >> s;
    tot += (int) s.size();
    string rs = s;
    reverse(rs.begin(), rs.end());
    Insert(rs);
  }
  long long res = 0;
  for (auto& s : g) {
    long long ans = tot + 1ll * n * (int) s.size();
    int p = 0;
    for (auto& u : s) {
      if (son[p][(int) (u - 'a')] == 0) {
        break;
      }
      p = son[p][(int) (u - 'a')];
      ans -= 2 * cnt[p];
    }
    res += ans;
  }
  cout << res << '\n';
  return 0;
}

