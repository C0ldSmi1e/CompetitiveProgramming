// 最长上升子序列
// len 为最长上升子序列长度
// f[i] 为以 a[i] 为结尾的最长上升子序列长度
// q[i] 为长度为 i 的上升子序列的最后一个数
int len = 1;
f[1] = 1;
q[1] = a[1];
for (int i = 2; i <= n; i ++ )
    if (a[i] > q[len])
    {
        q[ ++ len] = a[i];
        f[i] = len;
    }
    else
    {
        int l = 1, r = len;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (q[mid] >= a[i]) r = mid;
            else l = mid + 1;
        }
        q[r] = a[i];
        f[i] = r;
    }

// q.size() 为最长上升子序列长度
// f[i] 为以 a[i] 为结尾的最长上升子序列长度
// q[i] 为长度为 i 的上升子序列的最后一个数
vector<int> q, f(n);
f[0] = 1;
q.emplace_back(a[0]);
for (int i = 1; i < n; i ++ )
    if (a[i] > q.back())
    {
        q.emplace_back(a[i]);
        f[i] = (int) q.size();
    }
    else
    {
        int pos = (int) (lower_bound(q.begin(), q.end(), a[i]) - q.begin());
        q[pos] = a[i];
        f[i] = pos + 1;
    }

// 最长不下降子序列
// len 为最长不下降子序列长度
// f[i] 为以 a[i] 为结尾的最长不下降子序列长度
// q[i] 为长度为 i 的不下降子序列的最后一个数
int len = 1;
f[1] = 1;
q[1] = a[1];
for (int i = 2; i <= n; i ++ )
    if (a[i] >= q[len])
    {
        q[ ++ len] = a[i];
        f[i] = len;
    }
    else
    {
        int l = 1, r = len;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (q[mid] > a[i]) r = mid;
            else l = mid + 1;
        }
        q[r] = a[i];
        f[i] = r;
    }

// q.size() 为最长不下降子序列长度
// f[i] 为以 a[i] 为结尾的最长不下降子序列长度
// q[i] 为长度为 i 的不下降子序列的最后一个数
vector<int> q, f(n);
f[0] = 1;
q.emplace_back(a[0]);
for (int i = 1; i < n; i ++ )
    if (a[i] >= q.back())
    {
        q.emplace_back(a[i]);
        f[i] = (int) q.size();
    }
    else
    {
        int pos = (int) (upper_bound(q.begin(), q.end(), a[i]) - q.begin());
        q[pos] = a[i];
        f[i] = pos + 1;
    }

// 最长下降子序列
// len 为最长下降子序列长度
// f[i] 为以 a[i] 为结尾的最长下降子序列长度
// q[i] 为长度为 i 的下降子序列的最后一个数
int len = 1;
f[1] = 1;
q[1] = a[1];
for (int i = 2; i <= n; i ++ )
    if (a[i] < q[len])
    {
        q[ ++ len] = a[i];
        f[i] = len;
    }
    else
    {
        int l = 1, r = len;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (q[mid] <= a[i]) r = mid;
            else l = mid + 1;
        }
        q[r] = a[i];
        f[i] = r;
    }

// q.size() 为最长下降子序列长度
// f[i] 为以 a[i] 为结尾的最长下降子序列长度
// q[i] 为长度为 i 的下降子序列的最后一个数
vector<int> q, f(n);
f[0] = 1;
q.emplace_back(a[0]);
for (int i = 1; i < n; i ++ )
    if (a[i] < q.back())
    {
        q.emplace_back(a[i]);
        f[i] = (int) q.size();
    }
    else
    {
        int pos = (int) (lower_bound(q.begin(), q.end(), a[i], greater<int>()) - q.begin());
        q[pos] = a[i];
        f[i] = pos + 1;
    }

// 最长不上升子序列
// len 为最长不上升子序列长度
// f[i] 为以 a[i] 为结尾的最长不上升子序列长度
// q[i] 为长度为 i 的不上升子序列的最后一个数
int len = 1;
f[1] = 1;
q[1] = a[1];
for (int i = 2; i <= n; i ++ )
    if (a[i] <= q[len])
    {
        q[ ++ len] = a[i];
        f[i] = len;
    }
    else
    {
        int l = 1, r = len;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (q[mid] < a[i]) r = mid;
            else l = mid + 1;
        }
        q[r] = a[i];
        f[i] = r;
    }

// q.size() 为最长不上升子序列长度
// f[i] 为以 a[i] 为结尾的最长不上升子序列长度
// q[i] 为长度为 i 的不上升子序列的最后一个数
vector<int> q, f(n);
f[0] = 1;
q.emplace_back(a[0]);
for (int i = 1; i < n; i ++ )
    if (a[i] <= q.back())
    {
        q.emplace_back(a[i]);
        f[i] = (int) q.size();
    }
    else
    {
        int pos = (int) (upper_bound(q.begin(), q.end(), a[i], greater<int>()) - q.begin());
        q[pos] = a[i];
        f[i] = pos + 1;
    }

反链定理
最长上升子序列的个数=最长不上升子序列的长度，反之亦然。
最长下降子序列的个数=最长不下降子序列的长度，反之亦然。

//最长公共子序列
// n, m 分别为两个序列长度， f[][] 初始值为 0 
for (int i = 1; i <= n; i ++ )
    for (int j = 1; j <= m; j ++ )
    {
        f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        f[i][j] = max(f[i][j], f[i - 1][j - 1] + (int)(a[i] == b[j]));
    }
cout << f[n][m] << '\n';

// 最长公共上升子序列
for (int i = 1; i <= n; i ++ )
    {
        int mx = 0;
        for (int j = 1; j <= n; j ++ )
        {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j]) f[i][j] = max(f[i][j], mx + 1);
            if (a[i] > b[j]) mx = max(mx, f[i - 1][j]);
        }
    }
int res = 0;
for (int i = 1; i <= n; i ++ ) res = max(res, f[n][i]);
cout << res << '\n';

求最长回文子串用 Manacher 算法
求最长回文子序列将原序列翻转，与原序列求最长公共子序列
