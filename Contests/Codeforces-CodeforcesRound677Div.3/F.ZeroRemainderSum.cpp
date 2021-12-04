/**
*  Author: Daniel
*  Created Time: 2020-10-20 23:54:42
**/

// time-limit: 1000
#include <bits/stdc++.h>

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define EB emplace_back
#define SZ(x) (int)x.size()
#define MP(x, y) make_pair(x, y)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

// check the limitation!!!
const int N = 72, M = 1010;

int n, m, p;
int g[N][N];
int f[N][N][N][N];

// read the question carefully!!!
int main()
{
    IOS

    cin >> n >> m >> p;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            cin >> g[i][j];

    for (int i = 1; i <= n; i ++ )
    {
        for (int r = 0; r < p; r ++ )
            for (int cnt = 0; cnt <= m / 2; cnt ++ )
                f[i][0][0][r] = max(f[i][0][0][r], f[i - 1][m][cnt][r]);

        for (int j = 1; j <= m; j ++ )
            for (int cnt = 0; cnt <= j; cnt ++ )
                for (int r = 0; r < p; r ++ )
                {
                    // not choose
                    f[i][j][cnt][r] = max(f[i][j][cnt][r], f[i][j - 1][cnt][r]);

                    // choose
                    if (cnt && cnt <= m / 2)
                    {
                        int &t = f[i][j][cnt][(g[i][j] + f[i][j - 1][cnt - 1][r]) % p];
                        t = max(t, f[i][j - 1][cnt - 1][r] + g[i][j]);
                    }
                }
    }

    int res = 0;
    for (int cnt = 0; cnt <= m / 2; cnt ++ )
        res = max(res, f[n][m][cnt][0]);
    cout << res << '\n';
    return 0;
}
