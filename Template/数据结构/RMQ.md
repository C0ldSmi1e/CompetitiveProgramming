```C++
// 以最大值为例
const int N = 200010, M = 18;

int n, m, a[N];
int f[N][M];
int LOG2[N];

void init()
{
    for (int i = 2; i < N; i ++ ) LOG2[i] = LOG2[i / 2] + 1;
    for (int j = 0; j < M; j ++ )
        for (int i = 1; i + (1 << j) - 1 <= n; i ++ )
            if (!j) f[i][j] = a[i];
            else f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r)
{
    int len = r - l + 1;
    int k = LOG2[len];
    
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}
```

 