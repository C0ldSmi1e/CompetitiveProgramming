// 背包问题求具体方案
const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d%d", v + i, w + i);
    
    for (int i = n; i >= 1; i -- )
        for(int j = 0; j <= m; j ++ )
        {
            f[i][j] = f[i + 1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + w[i]);
        }
    
    int j = m;
    for (int i = 1; i <= n; i ++ )
        if (j >= v[i] && f[i][j] == f[i + 1][j - v[i]] + w[i])
        {
            printf("%d ", i);
            j -= v[i];
        }
    return 0;
}



// 背包问题求方案数
const int N = 1010, MOD = 1e9 + 7;

int n, m;
int f[N], g[N];

int main()
{
    scanf("%d%d", &n, &m);
    memset(f, -0x3f, sizeof f);
    f[0] = 0;
    g[0] = 1;
    for (int i = 0; i < n; i ++ )
    {
        int v, w;
        scanf("%d%d", &v, &w);
        for (int j = m; j >= v; j -- )
        {
            int maxa = max(f[j], f[j - v] + w);
            int cnt = 0;
            if (maxa == f[j]) cnt += g[j];
            if (maxa == f[j - v] + w) cnt = (cnt + g[j - v]) % MOD;
            f[j] = maxa, g[j] = cnt;
        }
    }
    int maxa = 0;
    for (int i = 0; i <= m; i ++ )
        maxa = max(maxa, f[i]);
    int res = 0;
    for (int i = 0; i <= m; i ++ )
        if (maxa == f[i])
            res = (res + g[i]) % MOD;
    printf("%d\n", res);
    return 0;
}



// 完全背包
const int N = 1010, M = 1010;

int n, m;
int v[N], w[N];
int f[N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i ++ )
        for (int j = v[i]; j <= m; j ++ )
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[m] << '\n';
    return 0;
}



// 单调队列优化多重背包
const int N = 1010, M = 20010;

int n, m;
int v[N], w[N], s[N];
int f[2][M];
int q[M];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i] >> s[i];
    for (int i = 1; i <= n; i ++ )
        for (int r = 0; r < v[i]; r ++ )
        {
            int hh = 0, tt = -1;
            for (int j = r; j <= m; j += v[i])
            {
                while (hh <= tt && (j - q[hh]) / v[i] > s[i]) hh ++ ;
                while (hh <= tt && f[i - 1 & 1][q[tt]] + (j - q[tt]) / v[i] * w[i] <= f[i - 1 & 1][j]) tt -- ;
                q[ ++ tt] = j;
                f[i & 1][j] = f[i - 1 & 1][q[hh]] + (j - q[hh]) / v[i] * w[i];
            }
        }
    cout << f[n & 1][m] << '\n';
    return 0;
}
