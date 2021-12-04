// 普通莫队
// 询问一段数中有多少种不同的数
// 也可以用树状数组按照右端点从小到大做
const int N = 50010, M = 200010, K = 1000010;

int n, m;
int len;
int w[N];
int cnt[K];
int ans[M];
struct Query {
  int id, l, r;
} q[M];

int get(int x) {
  return x / len;
}

bool cmp(const Query &a, const Query &b) {
  int al = get(a.l), bl = get(b.l);
  if (al != bl) {
    return al < bl;
  }
  return a.r < b.r;
}

void add(int x, int &res) {
  if (!cnt[x]) {
    res++;
  }
  cnt[x]++;
}

void del(int x, int &res) {
  cnt[x]--;
  if (!cnt[x]) {
    res--;
  }
}

int main() {
  SOS;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> w[i];
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int l, r;
    cin >> l >> r;
    q[i] = {i, l, r};
  }
  len = sqrt((double) n * n / m);
  sort(q + 1, q + 1 + m, cmp);
  for (int k = 1, i = 1, j = 0, res = 0; k <= m; k++) {
    int id = q[k].id, l = q[k].l, r = q[k].r;
    while (j < r) {
      add(w[++j], res);
    }
    while (j > r) {
      del(w[j--], res);
    }
    while (i < l) {
      del(w[i++], res);
    }
    while (i > l) {
      add(w[--i], res);
    }
    ans[id] = res;
  }
  for (int i = 1; i <= m; i ++ ) cout << ans[i] << '\n';
  return 0;
}



// 带修改莫队
// 问题和上面一样，但可以修改某些数
const int N = 10010, M = 1000010;

int n, m, mq, mc;
int w[N];
int cnt[M];
int len;
int ans[N];
struct Query {
  int id, l, r, t;
} q[M];
struct Modify {
  int p, col;
} modify[M];

int get(int x) {
  return x / len;
}

bool cmp(const Query &a, const Query &b) {
  int al = get(a.l), bl = get(b.l);
  int ar = get(a.r), br = get(b.r);
  if (al != bl) {
    return al < bl;
  }
  if (ar != br) {
    return ar < br;
  }
  return a.t < b.t;
}

void add(int x, int &res) {
  if (!cnt[x]) {
    res++;
  }
  cnt[x]++;
}

void del(int x, int &res) {
  cnt[x]--;
  if (!cnt[x]) {
    res--;
  }
}

int main() {
  SOS;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for (int i = 1; i <= m; i++) {
    string op;
    int l, r;
    cin >> op >> l >> r;
    if (op[0] == 'Q') {
      mq++;
      q[mq] = {mq, l, r, mc};
    } else {
      mc++;
      modify[mc] = {l, r};
    }
  }
  len = cbrt((double) n * mc) + 1;
  sort(q + 1, q + 1 + mq, cmp);
  for (int k = 1, i = 1, j = 0, now = 0, res = 0; k <= mq; k++) {
    int id = q[k].id, l = q[k].l, r = q[k].r, t = q[k].t;
    while (j < r) {
      add(w[++j], res);
    }
    while (j > r) {
      del(w[j--], res);
    }
    while (i < l) {
      del(w[i++], res);
    }
    while (i > l) {
      add(w[--i], res);
    }
    while (now < t) {
      now++;
      if (modify[now].p >= i && modify[now].p <= j) {
        del(w[modify[now].p], res);
        add(modify[now].col, res);
      }
      swap(w[modify[now].p], modify[now].col);
    }
    while (now > t) {
      if (modify[now].p >= i && modify[now].p <= j) {
        del(w[modify[now].p], res);
        add(modify[now].col, res);
      }
      swap(w[modify[now].p], modify[now].col);
      now--;
    }
    ans[id] = res;
  }
  for (int i = 1; i <= mq; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}



// 莫队求区间众数出现的次数
// 用 cnt[i] 维护数字i的出现次数
// 用 num[i] 维护出现了 i 次的数字有多少个
// 因此，最大的不为 0 的 num[] 的下标即为众数的出现次数
const int N = 300010, M = 1010;

int n, m;
int a[N];
int len;
int cnt[N], num[N];
int ans[N];
struct Query {
  int id, l, r;
} q[N];

inline int get(int x) {
  return x / len;
}

inline bool cmp(const Query &a, const Query &b) {
  int al = get(a.l), bl = get(b.l);
  if (al != bl) {
    return al < bl;
  }
  return a.r < b.r;
}

inline void add(int x, int &res) {
  num[cnt[x]]--;
  cnt[x]++;
  num[cnt[x]]++;
  while (num[res + 1]) {
    res++;
  }
}

inline void del(int x, int &res) {
  num[cnt[x]]--;
  cnt[x]--;
  num[cnt[x]]++;
  while (!num[res]) {
    res--;
  }
}

int main() {
  SOS;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    int l, r;
    cin >> l >> r;
    q[i] = {i, l, r};
  }
  len = max(1, (int) sqrt((double) n));
  sort(q + 1, q + 1 + m, cmp);
  num[0] = 1;
  // res 即为区间众数出现的次数
  for (int k = 1, i = 1, j = 0, res = 0; k <= m; k++) {
    int id = q[k].id, l = q[k].l, r = q[k].r;
    while (j < r) add(a[++ j], res);
    while (j > r) del(a[j--], res);
    while (i < l) del(a[i++], res);
    while (i > l) add(a[--i], res);
    if (2 * res <= r - l + 1) {
      ans[id] = 1;
    } else {
      ans[id] = 2 * res - (r - l + 1);
    }
  }
  for (int i = 1; i <= m; i ++ ) {
    cout << ans[i] << '\n';
  }
  return 0;
}
