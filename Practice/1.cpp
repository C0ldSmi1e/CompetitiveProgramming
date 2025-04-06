/**
 * Author: C0ldSmi1e
 * Created Time: 04/06/2025 07:38:02 AM
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

  string s = "What are you doing at the end of the world? Are you busy? Will you save us?";
  const int N = 100010;
  const long long INF = (long long) 1e18;
  vector<long long> len(N);
  len[0] = (int) s.size();
  string l = "What are you doing while sending \"";
  string m = "\"? Are you busy? Will you send \"";
  string r = "\"?";
  long long bad = -1;
  for (int i = 1; i < N; i++) {
    if (bad != -1) {
      len[i] = bad;
      continue;
    }
    len[i] = 2 * len[i - 1] + (int) l.size() + (int) m.size() + (int) r.size();
    if (len[i] >= INF) {
      bad = len[i];
    }
  }
  auto Dfs = [&](auto& self, int n, long long k) -> char {
    if (n == 0) {
      return s[k];
    }
    long long t = (len[n] - (int) l.size() - (int) m.size() - (int) r.size()) / 2;
    // l
    if (k < (int) l.size()) {
      return l[k];
    }
    // the first t
    if (k < (int) l.size() + t) {
      k -= (int) l.size();
      return self(self, n - 1, k);
    }
    // m
    if (k < (int) l.size() + t + (int) m.size()) {
      k -= (int) l.size() + t;
      return m[k];
    }
    // the second t
    if (k < (int) l.size() + t + (int) m.size() + t) {
      k -= (int) l.size() + t + (int) m.size();
      return self(self, n - 1, k);
    }
    // r
    k -= (int) l.size() + t + (int) m.size() + t;
    return r[k];
  };
  // l + t + m + t + r
  int T;
  cin >> T;
  while (T--) {
    int n;
    long long k;
    cin >> n >> k;
    if (k > len[n]) {
      cout << '.';
      continue;
    }
    k -= 1;
    cout << Dfs(Dfs, n, k);
  }
  return 0;
}
