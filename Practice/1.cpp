// tr[] 维护的是 a[] 的前缀和

int n;
LL a[N];
LL tr[N];

#define lowbit(x) (x & -x)

void add(int x, LL c) {
  for (int i = x; i <= n; i += lowbit(i)) {
    tr[i] += c;
  }
}

LL get(int x) {
  LL res = 0;
  for (int i = x; i; i -= lowbit(i)) {
    res += tr[i];
  }
  return res;
}

LL get(int l, int r) {
  return get(r) - get(l - 1);
}

void build(int n) {
  for (int i = 1; i <= n; i++) {
    add(i, a[i]);
  }
}
