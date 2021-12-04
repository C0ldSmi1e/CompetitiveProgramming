// KMP
// s[]是长文本，p[]是模式串，n是s的长度，m是p的长度
// 字符串下标均从 1 开始
// 求模式串的Next数组：
for (int i = 2, j = 0; i <= m; i ++ )
{
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == p[j + 1]) j ++ ;
    ne[i] = j;
}

// 匹配
for (int i = 1, j = 0; i <= n; i ++ )
{
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) j ++ ;
    if (j == m)
    {
        j = ne[j];
        // 匹配成功后的逻辑
    }
}



// Trie 树
int son[N][26], cnt[N], idx;
// 0号点既是根节点，又是空节点
// son[][]存储树中每个节点的子节点
// cnt[]存储以每个节点结尾的单词数量

// 插入一个字符串
void insert(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++ ;
}

// 查询字符串出现的次数
int query(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}



// Trie 树求 n 个整数的最大异或对
const int N = 100010;

int n;
int a[N];
int son[N * 32][2], idx;

void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i -- )
    {
        int u = (x >> i) & 1;
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
}

int find(int x)
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i -- )
    {
        int u = (x >> i) & 1;
        if (son[p][!u])
        {
            p = son[p][!u];
            res += 1 << i;
        }
        else p = son[p][u];
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ )
    {
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    int res = -0x3f3f3f3f;
    for (int i = 0; i < n; i ++ ) res = max(res, find(a[i]));
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
int get_min()
{
    int i = 0, j = 1;
    while (i < n && j < n)
    {
        int k = 0;
        while (k < n && t[i + k] == t[j + k]) k ++ ;
        if (k == n) break;
        if (t[i + k] > t[j + k]) i += k + 1;
        else j += k + 1;
        if (i == j) j ++ ;
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
void init()
{
    int k = 0;
    t[k ++ ] = '#';
    for (int i = 0; i < n; i ++ ) t[k ++ ] = s[i], t[k ++ ] = '#';
    n = k;
}

void manacher()
{
    int mr = 0, mid;
    for (int i = 0; i < n; i ++ )
    {
        if (i < mr) p[i] = min(p[mid * 2 - i], mr - i);
        else p[i] = 1;
        while (i - p[i] >= 0 && i + p[i] < n && t[i - p[i]] == t[i + p[i]]) p[i] ++ ;
        if (i + p[i] > mr)
        {
            mr = i + p[i];
            mid = i;
        }
    }
}
