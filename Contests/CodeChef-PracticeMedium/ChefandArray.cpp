/**
*  Author: Daniel
*  Created Time: 2020-10-15 19:12:47
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
const int N = 100010, M = 17;

int n, m;
int a[N];
int f[N][M];
int LOG2[N];
int x, y, k, l, r;

// read the question carefully!!!
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);

    for (int i = 2; i < N; i ++ ) LOG2[i] = LOG2[i >> 1] + 1;
    for (int j = 0; j < M; j ++ )
        for (int i = 1; i + (1 << j) - 1 <= n; i ++ )
            if (!j) f[i][j] = a[i];
            else f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);

    scanf("%d%d%d", &m, &x, &y);
    LL res = 0;
    while (m -- )
    {
        l = x + 1, r = y + 1;
        if (l > r) swap(l, r);
        k = LOG2[r - l + 1];
        res += max(f[l][k], f[r - (1 << k) + 1][k]);

        x += 7, y += 11;
        if (x >= n - 1) x %= n - 1;
        if (y >= n) y %= n;
    }
    cout << res << '\n';
    return 0;
}
