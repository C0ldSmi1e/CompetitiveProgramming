#include <iostream>

using namespace std;

const int N = 2010;

int n, mod;
int f[N][N];
int fact[N], infact[N];

int qp(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = (long long)res * a % mod;
        a = (long long)a * a % mod;
        b >>= 1;
    }
    return res;
}

int C(int a, int b)
{
    if (a < b) return 0;
    else return (long long)fact[a] * infact[b] % mod * infact[a - b] % mod;
}

void init(int n)
{
    fact[0] = infact[0] = 1;
    fact[1] = infact[1] = 1;
    for (int i = 2; i <= n; i ++ )
    {
        fact[i] = (long long)fact[i - 1] * i % mod;
        infact[i] = (long long)(mod - mod / i) * infact[mod % i] % mod;
    }
    for (int i = 2; i <= n; i ++ ) infact[i] = (long long)infact[i] * infact[i - 1] % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> mod;
    init(N - 1);
    f[0][0] = 1;
    for (int i = 1; i <= n; i ++ )
    {
        f[i][0] = qp(2, i - 1);
        for (int j = 1; j <= i; j ++ )
            for (int pos = 2; pos < i; pos ++ )
            {
                int len = i - pos;
                f[i][j] = (f[i][j] + (long long)qp(2, len - 1) * f[pos - 1][j - 1] % mod * C(i - j, len) % mod) % mod;
            }
    }
    int res = 0;
    for (int j = 0; j <= n; j ++ ) res = (res + f[n][j]) % mod;
    cout << res << '\n';
    return 0;
}
