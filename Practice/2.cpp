#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, M = 1 << 6, K = 21, MOD = 1e9 + 7;

int n, m, k;
int f[N][M][M][K];

int get_count(int x)
{
    int res = 0;
    while (x)
    {
        res ++ ;
        x -= x & -x;
    }
    return res;
}

int main()
{
    cin >> n >> m >> k;
    f[0][0][0][0] = 1;

    int cnt = 0;
    for (int i = 1; i <= m; i ++ )
        for (int a = 0; a < 1 << n; a ++ )
            for (int b = 0; b < 1 << n; b ++ )
            {
                if (a & (b << 2) || b & (a << 2)) continue;
                for (int c = 0; c < 1 << n; c ++ )
                {
                    if (c & (b << 2) || b & (c << 2)) continue;
                    if (c & (a << 1) || a & (c << 1)) continue;
                    int t = get_count(c);
                    for (int u = t; u <= k; u ++, cnt ++ )
                        f[i][b][c][u] = (f[i][b][c][u] + f[i - 1][a][b][u - t]) % MOD;
                }
            }

    int res = 0;
    int t = 0;
    for (int i = 0; i < 1 << n; i ++ )
        for (int j = 0; j < 1 << n; j ++ )
        {
          for (int cc = 0; cc <= k; cc++) {
            t += f[4][i][j][cc];
          }
            res = (res + f[2][i][j][k]) % MOD;
        }
    cout << t << endl;

    cout << res << endl;
    return 0;
}
