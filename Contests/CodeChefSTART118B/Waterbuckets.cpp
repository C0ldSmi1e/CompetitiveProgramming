/**
 * Author: C0ldSmi1e
 * Created Time: 02/13/2024 10:24:56 PM
**/

// time-limit: 2500
// problem-url: https://www.codechef.com/START118B/problems/WATERBUCKETS
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
class Fenwick {
 public:
  vector<T> fenw;
  int n;
  Fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
  inline void Add(int x, T v) {
    assert(x >= 0 && x < n);
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
  inline T Get(int x) {
    T res{};
    while (x >= 0) {
      res += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return res;
  }
  inline T Get(int l, int r) {
    assert(l >= 0 && l < n && r >= 0 && r < n);
    T res = Get(r);
    if (l - 1 >= 0) {
      res -= Get(l - 1);
    }
    return res;
  }
  inline int KthMin(int k) {
    // KthMax = n - KthMin + 1
    assert(k >= 1 && k <= n);
    int cnt = 0, x = 0;
    for (int i = (int) log2(n); i >= 0; i--) {
      x += (1 << i);
      if (x >= n || cnt + fenw[x - 1] >= k) {
        x -= (1 << i);
      } else {
        cnt += fenw[x - 1];
      }
    }
    return x;
  }
};

// struct Node {
//   int a = ...; // don't forget to set default value
//   inline void operator += (Node& other) {
//     ...
//   }
// };

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n;
  long long m;
  cin >> n >> m;
  vector<int> a(n);
  Fenwick<long long> fenw(n);
  const int K = (int) sqrt(n) + 1;
  vector<long long> x(n);
  vector<long long> y(n);
  auto Update = [&](int i) -> void {
    // [i / K * K, (i / K + 1) * K)
    int j = min(n - 1, (i / K + 1) * K - 1);
    x[j] = 1;
    y[j] = a[j];
    long long sum = a[j];
    j -= 1;
    bool last = true;
    while (j >= i / K * K) {
      if (sum + a[j] > m) {
        x[j] = x[j + 1] + 1;
        y[j] = y[j + 1];
        last = false;
        sum = a[j];
        j -= 1;
        continue;
      }
      sum += a[j];
      x[j] = x[j + 1];
      if (last) {
        y[j] = y[j + 1] + a[j];
      } else {
        y[j] = y[j + 1];
      }
      j -= 1;
    }
  };
  auto Query = [&](int l, int r) -> long long {
    assert(l <= r);
    long long ans = 0;
    long long sum = 0;
    if (l / K == r / K) {
      ans = 1;
      for (int i = l; i <= r; i++) {
        if (sum + a[i] > m) {
          sum = 0;
          ans += 1;
        }
        sum += a[i];
      }
      return ans;
    }
    ans = x[l];
    sum = y[l];
    l = (l / K + 1) * K;
    while (l / K != r / K) {
      int i = l - 1;
      int j = min(n - 1, (l / K + 1) * K - 1);
      while (i < j) {
        int mid = (i + j + 1) >> 1;
        if (sum + fenw.Get(l, mid) <= m) {
          i = mid;
        } else {
          j = mid - 1;
        }
      }
      if (i == l - 1) {
        sum = 0;
      }
      if (i == min(n - 1, (l / K + 1) * K - 1)) {
        sum += fenw.Get(l / K, i);
      } else {
        i += 1;
        ans += x[i];
        sum = y[i];
      }
      l = (l / K + 1) * K;
    }
    for (int i = l; i <= r; i++) {
      if (sum + a[i] > m) {
        sum = 0;
        ans += 1;
      }
      sum += a[i];
    }
    return ans;
  };
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    Update(i);
    fenw.Add(i, a[i]);
  }
  //for (int i = 0; i < n; i++) {
  //  cout << fenw.Get(i, i) << " \n"[i == n - 1];
  //}
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r;
      cin >> l >> r;
      --l;
      --r;
      cout << Query(l, r) << '\n';
    } else {
      int i, t;
      cin >> i >> t;
      --i;
      fenw.Add(i, -a[i]);
      a[i] = t;
      fenw.Add(i, a[i]);
      Update(i);
      //debug(a);
      //debug(x);
      //debug(y);
    }
  }
  return 0;
}
