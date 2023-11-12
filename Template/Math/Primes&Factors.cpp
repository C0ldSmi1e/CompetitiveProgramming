// 试除法判断质数
bool IsPrime(int x) {
  if (x < 2) {
    return false;
  }
  for (int i = 2; i <= x / i; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}



// 朴素筛求质数
int primes[N], cnt;  // primes[] 存储所有素数
bool st[N];  // st[x] 存储 x 是否被筛掉

void GetPrimes(int n) {
  for (int i = 2; i <= n; i++) {
    if (st[i]) {
      continue;
    }
    primes[cnt++] = i;
    for (int j = i + i; j <= n; j += i) {
      st[j] = true;
    }
  }
}



// 试除法求约数
vector<int> get_divisors(int x) {
  vector<int> res;
  for (int i = 1; i <= x / i; i++)
    if (x % i == 0) {
      res.push_back(i);
      if (i != x / i) {
        res.push_back(x / i);
      }
    }
  sort(res.begin(), res.end());
  return res;
}



// 试除法分解质因数
void get(int x) {
  map<int, int> fac;
  for (int i = 2; i <= n / i; i++) {
    if (n % i == 0) {
      int t = 0;
      while (n % i == 0) {
        n /= i;
        t++;
      }
      fac[i] = t;
    }
  }
  if (n > 1) {
    fac[n] += 1;
  }
}



// 线性筛法优化分解质因数
// 该方法利用了线性筛法可以保存某个数的大于 1 的最小质因子的性质
int primes[N], cnt;
int minp[N];  // 保存某个数的大于 1 的最小质因子
bool st[N];

void init(int n) {
  st[1] = true;
  for (int i = 2; i <= n; i++) {
    if (!st[i]) {
      minp[i] = i;
      primes[cnt++] = i;
    }
    for (int j = 0; primes[j] <= n / i; j++) {
      int t = primes[j] * i;
      st[t] = true;
      minp[t] = primes[j];
      if (i % primes[j] == 0) {
        break;
      }
    }
  }
}

// 需要分解的数
int n;
// 执行筛法
init(N - 1);
// 因子和因子的次数
vector<int> fac, cnt;

while (n > 1) {
  int p = minp[n], t = 0;
  while (n % p == 0) {
    n /= p;
    t++;
  }
  fac.push_back(p);
  cnt.push_back(t);
}



// 线性筛求各种信息
// 可以求每个数的：
// 最小质因子、质因子的种数、最小质因子的幂次
// 因子个数、因子之和
int primes[N], cnt;  // 存放所有质数， cnt 为个数
int minp[N];  // minp[i] 表示 i 的最小质因子
int pcnt[N];  // 表示 i 有 pcnt[i] 个不同的质因子
int minp_cnt[N];  // 最小质因子的幂次
int fac_cnt[N];  // 因子个数
int fac_sum[N];  // 因子之和
int exminp[N];  // 除了最小质因子外的因子之和
bool st[N];  // st[i] 为 false 表示 i 为质数

void init(int n) {
  st[1] = true;
  fac_sum[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!st[i]) {
        minp[i] = i;
        primes[cnt++] = i;
        fac_cnt[i] = 2;
        fac_sum[i] = i + 1;
        minp_cnt[i] = 1;
        exminp[i] = 1;
    }
    for (int j = 0; primes[j] <= n / i; j++) {
      int t = primes[j] * i;
      st[t] = true;
      minp[t] = primes[j];
      if (i % primes[j] == 0) {
        fac_cnt[t] = fac_cnt[i] / (minp_cnt[i] + 1) * (minp_cnt[i] + 2);
        fac_sum[t] = fac_sum[i] * primes[j] + exminp[i];
        exminp[t] = exminp[i];
        minp_cnt[t] = minp_cnt[t] + 1;
        break;
      }
      fac_cnt[t] = fac_cnt[i] * fac_cnt[primes[j]];
      fac_sum[t] = fac_sum[i] * fac_sum[primes[j]];
      exminp[t] = fac_sum[i];
      minp_cnt[t] = 1;
    }
  }
  for (int i = 2; i <= n; i++) {
    int j = i / minp[i];
    pcnt[i] = pcnt[j] + (int) (minp[i] != minp[j]);
  }
}


/**
 * 如果 N = p1^c1 * p2^c2 * ... *pk^ck
 * 约数个数： (c1 + 1) * (c2 + 1) * ... * (ck + 1)
 * 约数之和： (p1^0 + p1^1 + ... + p1^c1) * ... * (pk^0 + pk^1 + ... + pk^ck)
 *           =((p1^(c1+1)-1) / (p1-1)) * ... * ((pk^(ck+1)-1) / (pk-1))
 * 约数之积：N^(cnt/2), cnt 为约数个数
**/
