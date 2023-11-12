// 直接递推
// c[a][b] 表示从a个苹果中选b个的方案数
for (int i = 0; i < N; i++) {
  for (int j = 0; j <= i; j++) {
    if (!j) {
      c[i][j] = 1;
    } else {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
}



// 预处理逆元
// 首先预处理出所有阶乘取模的余数fact[N]，以及所有阶乘取模的逆元infact[N]
// 如果取模的数是质数，可以用费马小定理求逆元
// C(a, b) = fact[a] * infact[a - b] * infact[b]
int qp(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = (LL) res * a % mod;
    }
    a = (LL) a * a % mod;
    b >>= 1;
  }
  return res;
}

int C(int a, int b) {
  if (a < b) {
    return 0;
  }
	int res = (LL) fact[a] * infact[a - b] % mod * infact[b] % mod;
	return res;
}

// 预处理阶乘的余数和阶乘逆元的余数
void init(int n) {
  // fact[0] = infact[0] = 1;
  // for (int i = 1; i <= n; i ++ )
  // {
  //     fact[i] = (LL)fact[i - 1] * i % mod;
  //     infact[i] = (LL)infact[i - 1] * qp(i, mod - 2) % mod;
  // }
  fact[0] = infact[0] = 1;
  fact[1] = infact[1] = 1;
  for (int i = 2; i <= n; i++) {
    fact[i] = (LL) fact[i - 1] * i % mod;
    infact[i] = (LL) (mod - mod / i) * infact[mod % i] % mod;
  }
  for (int i = 2; i < N; i++) {
    infact[i] = (LL) infact[i] * infact[i - 1] % mod;
  }
}



// 卢卡斯定理
// 若p是质数，则对于任意整数 1 <= m <= n，有：
// C(n, m) = C(n % p, m % p) * C(n / p, m / p) (mod p)
// 需要逆元, 也可以直接在逆元模板的基础上加上lucas部分
int qp(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = (LL) res * a % mod;
    }
    a = (LL) a * a % mod;
    b >>= 1;
  }
  return res;
}

int C(int a, int b) {
  if (a < b) {
    return 0;
  }
  int res = 1;
  for (int i = 1, j = a; i <= b; i++, j--) {
    res = (LL) res * j % p;
    res = (LL) res * qp(i, p - 2) % p;
  }
  return res;
}

int lucas(LL a, LL b) {
  if (a < p && b < p) {
    return C(a, b);
  }
  return (LL) C(a % p, b % p) * lucas(a / p, b / p) % p;
}



// 当我们需要求出组合数的真实值，而非对某个数的余数时，分解质因数的方式比较好用：
// 1. 筛法求出范围内的所有质数
// 2. 通过 C(a, b) = a! / b! / (a - b)! 这个公式求出每个质因子的次数。 
//  n! 中p的次数是 n / p + n / p^2 + n / p^3 + ...
// 3. 用高精度乘法将所有质因子相乘
int primes[N], cnt;     // 存储所有质数
int sum[N];     // 存储每个质数的次数
bool st[N];     // 存储每个数是否已被筛掉

// 线性筛法求素数
void get_primes(int n) {
  for (int i = 2; i <= n; i++) {
    if (!st[i]) {
      primes[cnt++] = i;
    }
    for (int j = 0; primes[j] <= n / i; j++) {
      st[primes[j] * i] = true;
      if (i % primes[j] == 0) {
        break;
      }
    }
  }
}

// 求n！中的次数
int get(int n, int p) {
  int res = 0;
  while (n) {
    res += n / p;
    n /= p;
  }
  return res;
}

// 高精度乘低精度模板
vector<int> mul(vector<int> &A, int b) {
  vector<int> C;
  int t = 0;
  for (int i = 0; i < (int) A.size() || t; i++) {
    if (i < A.size()) {
      t += A[i] * b;
    }
    C.push_back(t % 10);
    t /= 10;
  }
  return C;
}

// 预处理范围内的所有质数
get_primes(a);  

// 求每个质因数的次数
for (int i = 0; i < cnt; i++) {
  int p = primes[i];
  sum[i] = get(a, p) - get(b, p) - get(a - b, p);
}

vector<int> res;
res.push_back(1);

// 用高精度乘法将所有质因子相乘
for (int i = 0; i < cnt; i++) {
  for (int j = 0; j < sum[i]; j++) {
    res = mul(res, primes[i]);
  }
}



/**
 * 卡特兰数：
 * // 1 1 2 5 14 42 132 ...
 * // n >= 2, n 为正自然数
 * Cat[n] = C(2 * n, n) / (n + 1)
 *        = C(2 * n, n) - C(2 * n, n - 1)
 *        = (4 * n - 2) * Cat[n - 1]
 *        = Cat[n - i] * Cat[i - 1] // i is in [1, n], Cat[0] = Cat[1] = 1
**/

/**
 * 隔板法：
 * 若能转换为 x1+x2+...+xn=k ，就可以看作在 k 个小球中插入 k-1 个隔板
 * 若能转换为 x1+x2+...+xn<=k ，就可以看作在 k 个小球中插入 k 个隔板
**/


// 简易版模数

constexpr int mod = ...;

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

/*
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
*/
