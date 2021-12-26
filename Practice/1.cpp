#include <bits/stdc++.h>

using namespace std;

constexpr int mod = (int) 1e9 + 7;

// assume -mod <= x < 2 * mod
int norm(int x) {
  if (x < 0) {
    x += mod;
  }
  if (x >= mod) {
    x -= mod;
  }
  return x;
}

template<typename T, typename U>
T qp(const T &a, const U &b) {
  assert(b >= 0);
  T res = 1, x = a;
  U p = b;
  for (; p; p /= 2, x *= x) {
    if (p % 2) {
      res *= x;
    }
  }
  return res;
}

class Mint {
 public:
  int x;
  Mint(int x = 0) : x(norm(x)) {}
  int val() const {
    return x;
  }
  Mint operator-() const {
    return Mint(norm(mod - x));
  }
  Mint inv() const {
    assert(x != 0);
    return qp(*this, mod - 2);
  }
  Mint &operator*=(const Mint &rhs) {
    x = (int) ((long long) x * rhs.x % mod);
    return *this;
  }
  Mint &operator+=(const Mint &rhs) {
    x = norm(x + rhs.x);
    return *this;
  }
  Mint &operator-=(const Mint &rhs) {
    x = norm(x - rhs.x);
    return *this;
  }
  Mint &operator/=(const Mint &rhs) {
      return *this *= rhs.inv();
  }
  friend Mint operator*(const Mint &lhs, const Mint &rhs) {
    Mint res = lhs;
    res *= rhs;
    return res;
  }
  friend Mint operator+(const Mint &lhs, const Mint &rhs) {
    Mint res = lhs;
    res += rhs;
    return res;
  }
  friend Mint operator-(const Mint &lhs, const Mint &rhs) {
      Mint res = lhs;
      res -= rhs;
      return res;
  }
  friend Mint operator/(const Mint &lhs, const Mint &rhs) {
    Mint res = lhs;
    res /= rhs;
    return res;
  }
};

vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);
 
Mint C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}

Mint Fact(int n) {
  assert(n >= 0);
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  auto s = [&](int x, int y) -> Mint {
    Mint res = 0;
    for (int i = 0; i <= x; i++) {
      res += C(y + i + 1, i + 1);
    }
    return res;
  };
  Mint res = s(x2, y2) - s(x1 - 1, y2) - s(x2, y1 - 1) + s(x1 - 1, y1 - 1);
  cout << res.val() << '\n';
  return 0;
}
