// phi[n] 为 [1,n] 中，和 n 互质的数的个数

// 直接求欧拉函数
int phi(int x) {
  int res = x;
  for (int i = 2; i <= x / i; i++) {
    if (x % i == 0) {
      res = res / i * (i - 1);
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    res = res / x * (x - 1);
  }
  return res;
}



// 筛法求欧拉函数
int primes[N], cnt;  // primes[]存储所有素数
int phi[N];  // 存储每个数的欧拉函数
bool st[N];  // st[x]存储x是否被筛掉

void GetEulers(int n) {
  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!st[i]) {
      primes[cnt ++ ] = i;
      phi[i] = i - 1;
    }
    for (int j = 0; primes[j] <= n / i; j++) {
      int t = primes[j] * i;
      st[t] = true;
      if (i % primes[j] == 0) {
        phi[t] = phi[i] * primes[j];
        break;
      }
      phi[t] = phi[i] * (primes[j] - 1);
    }
  }
}
