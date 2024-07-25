/**
 * Author: C0ldSmi1e
 * Created Time: 03/16/2024 08:18:28 AM
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1944/problem/D
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

/*
 * hash seed:
 * 131, 13331, 146527, 19260817, 378551
 * 63689, 1315423911, 5381, 65599, 131313
 * mod:
 * 1000000007, 1000000009, 998244353
*/

/*
random_device rd;
mt19937_64 rng{rd()};
*/

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// [l, r]
template <typename T>
T Rand(T l, T r) {
  uniform_int_distribution<T> d(l, r);
  return d(rng);
}

template <typename T>
T RealRand(T l, T r) {
  uniform_real_distribution<T> d(l, r);
  return d(rng);
}

// long long Rand(long long l, long long r) {
//   return (rng() % (r + 1 - l)) + l;
// }

class StringHash {
 public:
  int n;
  unsigned long long seed, mod;
  vector<unsigned long long> p, h;
 
  StringHash(const string& s, unsigned long long _seed, unsigned long long _mod = 1000000007) : seed(_seed), mod(_mod) {
    n = static_cast<int>(s.size());
    p.resize(n + 1);
    h.resize(n + 1);
    p[0] = 1;
    for (int i = 0; i < n; i++) {
#ifdef STRING_HASH_MOD
      p[i + 1] = p[i] * seed % mod;
      h[i + 1] = (h[i] * seed + s[i]) % mod;
#else
      p[i + 1] = p[i] * seed;
      h[i + 1] = h[i] * seed + s[i];
#endif
    }
  }
  // return hash code [l, r)
  inline unsigned long long Get(int l, int r) {
    assert(l >= 0 && r <= n && l <= r);
#ifdef STRING_HASH_MOD
    return (h[r] - h[l] * p[r - l] % mod + mod) % mod;
#else
    return h[r] - h[l] * p[r - l];
#endif
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    vector<vector<int>> pref(26, vector<int>(n + 1));
    for (int c = 0; c < 26; c++) {
      for (int i = 0; i < n; i++) {
        pref[c][i + 1] = pref[c][i] + (int) (s[i] == (char) (c + 'a'));
      }
    }
    int seed = 1000 + Rand<int>(0, 999999999);
    StringHash sh(s, seed);
    StringHash th(t, seed);
    auto Check = [&](int l, int r) -> bool {
      return sh.Get(l, r - 2) == sh.Get(l + 2, r);
    };
    while (q--) {
      int sl, sr;
      cin >> sl >> sr;
      --sl;
      if (sr - sl == 1) {
        cout << "0\n";
        continue;
      }
      if (sr - sl == 2) {
        if (s[sl] == s[sl + 1]) {
          cout << "0\n";
        } else {
          cout << "2\n";
        }
        continue;
      }
      int tr = n - sl;
      int tl = n - sr;
      //debug(sl, sr, tl, tr);
      long long tot = 1ll * (1 + sr - sl) * (sr - sl) / 2ll;
      if (sh.Get(sl, sr) == th.Get(tl, tr)) {
        //debug("hh");
        if (pref[(int) (s[sl] - 'a')][sr] - pref[(int) (s[sl] - 'a')][sl] == sr - sl) {
          cout << "0\n";
        } else {
          if ((sr - sl) % 2 == 1 && Check(sl, sr)) {
            // acacaca
            cout << tot - 1ll * (1 + sr - sl) * ((sr - sl + 1) / 2) / 2 << '\n';
          } else {
            cout << tot - (sr - sl) - 1 << '\n';
          }
        }
      } else {
        if ((sr - sl) % 2 == 0 && Check(sl, sr)) {
          // acacac
          cout << tot - 1ll * (1 + sr - sl - 1) * ((sr - sl) / 2) / 2 << '\n';
        } else {
          cout << tot - 1 << '\n';
        }
      }
    }
  }
  return 0;
}
