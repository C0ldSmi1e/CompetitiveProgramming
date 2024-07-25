// KMP
// s[]是长文本，p[]是模式串，n是s的长度，m是p的长度
// 字符串下标均从 1 开始
// 求模式串的Next数组：
for (int i = 2, j = 0; i <= m; i++) {
  while (j && p[i] != p[j + 1]) {
    j = ne[j];
  }
  if (p[i] == p[j + 1]) {
    j++;
  }
  ne[i] = j;
}

// 匹配
for (int i = 1, j = 0; i <= n; i++) {
  while (j && s[i] != p[j + 1]) {
    j = ne[j];
  }
  if (s[i] == p[j + 1]) {
    j++;
  }
  if (j == m) {
    j = ne[j];
    // 匹配成功后的逻辑
  }
}



// KMP 2
template <typename T>
vector<int> kmpTable(int n, const T& s) {
  vector<int> p(n, 0);
  int k = 0;
  for (int i = 1; i < n; i++) {
    while (k > 0 && !(s[i] == s[k])) {
      k = p[k - 1];
    }
    if (s[i] == s[k]) {
      k++;
    }
    p[i] = k;
  }
  return p;
}

template <typename T>
vector<int> kmpTable(const T& s) {
  return kmpTable((int) s.size(), s);
}

template <typename T>
vector<int> kmpSearch(int n, const T& s, int m, const T& w, const vector<int>& p) {
  assert(n >= 1 && (int) p.size() == n);
  vector<int> res;
  int k = 0;
  for (int i = 0; i < m; i++) {
    while (k > 0 && (k == n || !(w[i] == s[k]))) {
      k = p[k - 1];
    }
    if (w[i] == s[k]) {
      k++;
    }
    if (k == n) {
      res.push_back(i - n + 1);
    }
  }
  // returns 0-indexed positions of occurrences of s in w
  return res;
}

template <typename T>
vector<int> kmpSearch(const T& s, const T& w, const vector<int>& p) {
  return kmpSearch((int) s.size(), s, (int) w.size(), w, p);
}



// Trie 树
int son[N][26], cnt[N], idx;
// 0号点既是根节点，又是空节点
// son[][]存储树中每个节点的子节点
// cnt[]存储以每个节点结尾的单词数量

// 插入一个字符串
void insert(char *str) {
  int p = 0;
  for (int i = 0; str[i]; i++) {
    int u = (int) (str[i] - 'a');
    if (!son[p][u]) {
      son[p][u] = ++idx;
    }
    p = son[p][u];
  }
  cnt[p]++;
}

// 查询字符串出现的次数
int query(char *str) {
  int p = 0;
  for (int i = 0; str[i]; i++) {
    int u = (int) (str[i] - 'a');
    if (!son[p][u]) {
      return 0;
    }
    p = son[p][u];
  }
  return cnt[p];
}



// Trie 树求 n 个整数的最大异或对
const int N = 100010;

int n;
int a[N];
int son[N * 32][2], idx;

void insert(int x) {
  int p = 0;
  for (int i = 30; i >= 0; i--) {
    int u = (x >> i) & 1;
    if (!son[p][u]) {
      son[p][u] = ++idx;
    }
    p = son[p][u];
  }
}

int find(int x) {
  int p = 0, res = 0;
  for (int i = 30; i >= 0; i--) {
    int u = (x >> i) & 1;
    if (son[p][!u]) {
      p = son[p][!u];
      res += 1 << i;
    } else {
      p = son[p][u];
    }
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    insert(a[i]);
  }
  int res = -0x3f3f3f3f;
  for (int i = 0; i < n; i++) {
    res = max(res, find(a[i]));
  }
  printf("%d\n", res);
  return 0;
}



// 字符串哈希
typedef unsigned long long ULL;
const ULL P = 13331 // 131
ULL h[N], p[N]; // h[k]存储字符串前k个字母的哈希值, p[k]存储 P^k mod 2^64

// 初始化
p[0] = 1;
for (int i = 1; i <= n; i ++ )
{
    h[i] = h[i - 1] * P + str[i];
    p[i] = p[i - 1] * P;
}

// 计算子串 str[l ~ r] 的哈希值
ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}



// 最小表示法
// 把一个长为len的字符串围成一个圈
// 然后以任意一个字符作为起点，都会产生一个新的长为len的字符串
// 字符串的最小表示就是所有新字符串中字典序最小的那个
int n;  // n 为原串长度
string s, t;  // s为原串，t为s的两倍

// 返回最小表示法的开头字母坐标
int get_min() {
  int i = 0, j = 1;
  while (i < n && j < n) {
    int k = 0;
    while (k < n && t[i + k] == t[j + k]) {
      k++;
    }
    if (k == n) {
      break;
    }
    if (t[i + k] > t[j + k]) {
      i += k + 1;
    } else {
      j += k + 1;
    }
    if (i == j) {
      j++;
    }
  }
  return min(i, j);
}



// Manacher 求最长回文串
// 结果为 max(p[i]) - 1
// 以下代码读入时下标从 0 开始
// 复杂度为 O(nlogn)
int n;
int p[N];  // p[i]为以t[i]为中心的最长回文串半径
char s[N], t[N];  // 原串、预处理后的串

// 预处理，在s中每个间隔插入未出现的字符
void init() {
  int k = 0;
  t[k++] = '#';
  for (int i = 0; i < n; i++) {
    t[k++] = s[i];
    t[k++] = '#';
  }
  n = k;
}

void manacher() {
  int mr = 0, mid;
  for (int i = 0; i < n; i++) {
    if (i < mr) {
      p[i] = min(p[mid * 2 - i], mr - i);
    } else {
      p[i] = 1;
    }
    while (i - p[i] >= 0 && i + p[i] < n && t[i - p[i]] == t[i + p[i]]) {
      p[i]++;
    }
    if (i + p[i] > mr) {
      mr = i + p[i];
      mid = i;
    }
  }
}

// Manacher 2
template <typename T>
vector<int> manacher(int n, const T &s) {
  if (n == 0) {
    return vector<int>();
  }
  vector<int> res(2 * n - 1, 0);
  int l = -1, r = -1;
  for (int z = 0; z < 2 * n - 1; z++) {
    int i = (z + 1) >> 1;
    int j = z >> 1;
    int p = (i >= r ? 0 : min(r - i, res[2 * (l + r) - z]));
    while (j + p + 1 < n && i - p - 1 >= 0) {
      if (!(s[j + p + 1] == s[i - p - 1])) {
        break;
      }
      p++;
    }
    if (j + p > r) {
      l = i - p;
      r = j + p;
    }
    res[z] = p;
  }
  return res;
  // res[2 * i] = odd radius in position i
  // res[2 * i + 1] = even radius between positions i and i + 1
  // s = "abaa" -> res = {0, 0, 1, 0, 0, 1, 0}
  // in other words, for every z from 0 to 2 * n - 2:
  // calculate i = (z + 1) >> 1 and j = z >> 1
  // now there is a palindrome from i - res[z] to j + res[z]
  // (watch out for i > j and res[z] = 0)
}
template <typename T>
vector<int> manacher(const T &s) {
  return manacher((int) s.size(), s);
}



template <typename T>
vector<int> SuffixArray(int n, const T &s, int char_bound) {
  vector<int> a(n);
  if (n == 0) {
    return a;
  }
  if (char_bound != -1) {
    vector<int> aux(char_bound, 0);
    for (int i = 0; i < n; i++) {
      aux[s[i]]++;
    }
    int sum = 0;
    for (int i = 0; i < char_bound; i++) {
      int add = aux[i];
      aux[i] = sum;
      sum += add;
    }
    for (int i = 0; i < n; i++) {
      a[aux[s[i]]++] = i;
    }
  } else {
    iota(a.begin(), a.end(), 0);
    sort(a.begin(), a.end(), [&s](int i, int j) { return s[i] < s[j]; });
  }
  vector<int> sorted_by_second(n);
  vector<int> ptr_group(n);
  vector<int> new_group(n);
  vector<int> group(n);
  group[a[0]] = 0;
  for (int i = 1; i < n; i++) {
    group[a[i]] = group[a[i - 1]] + (!(s[a[i]] == s[a[i - 1]]));
  }
  int cnt = group[a[n - 1]] + 1;
  int step = 1;
  while (cnt < n) {
    int at = 0;
    for (int i = n - step; i < n; i++) {
      sorted_by_second[at++] = i;
    }
    for (int i = 0; i < n; i++) {
      if (a[i] - step >= 0) {
        sorted_by_second[at++] = a[i] - step;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      ptr_group[group[a[i]]] = i;
    }
    for (int i = 0; i < n; i++) {
      int x = sorted_by_second[i];
      a[ptr_group[group[x]]++] = x;
    }
    new_group[a[0]] = 0;
    for (int i = 1; i < n; i++) {
      if (group[a[i]] != group[a[i - 1]]) {
        new_group[a[i]] = new_group[a[i - 1]] + 1;
      } else {
        int pre = (a[i - 1] + step >= n ? -1 : group[a[i - 1] + step]);
        int cur = (a[i] + step >= n ? -1 : group[a[i] + step]);
        new_group[a[i]] = new_group[a[i - 1]] + (pre != cur);
      }
    }
    swap(group, new_group);
    cnt = group[a[n - 1]] + 1;
    step <<= 1;
  }
  return a;
}

template <typename T>
vector<int> SuffixArray(const T &s, int char_bound) {
  return SuffixArray((int) s.size(), s, char_bound);
}

template <typename T>
vector<int> BuildLcp(int n, const T &s, const vector<int> &sa) {
  assert((int) sa.size() == n);
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    pos[sa[i]] = i;
  }
  vector<int> lcp(max(n - 1, 0));
  int k = 0;
  for (int i = 0; i < n; i++) {
    k = max(k - 1, 0);
    if (pos[i] == n - 1) {
      k = 0;
    } else {
      int j = sa[pos[i] + 1];
      while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
        k++;
      }
      lcp[pos[i]] = k;
    }
  }
  return lcp;
}

template <typename T>
vector<int> BuildLcp(const T &s, const vector<int> &sa) {
  return BuildLcp((int) s.size(), s, sa);
}



// z[i] is the length of the longest common prefix
// between s and the suffix of s starting at i
template <typename T>
vector<int> ZFunction(int n, const T &s) {
  vector<int> z(n, n);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    z[i] = (i > r ? 0 : min(r - i + 1, z[i - l]));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}

template <typename T>
vector<int> ZFunction(const T &s) {
  return ZFunction((int) s.size(), s);
}
