/**
* Author: Name
* Created Time: 2020-11-17 23:04:33
**/

// time-limit: 1000
#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define EB emplace_back
#define lowbit(x) (x & -x)
#define SZ(x) (int)(x.size())
#define MP(x, y) make_pair(x, y)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define SOS; ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

typedef long long LL;
typedef pair<int, int> PII;

template <typename A> using VE = vector<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;
    
///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 1010, M = 1010;

int T;
int n, m;
char g[N][N];
VE<PII> res;

int get(int i, int j)
{
    int cnt = 0;
    for (int k = i; k <= i + 1; k ++ )
        for (int l = j; l <= j + 1; l ++ )
            cnt += g[k][l] == '1';
    return cnt;
}

void go1_2(int i, int j)
{
    int cnt = 0;
    bool flag = false;
    for (int k = i; k <= i + 1; k ++ )
        for (int l = j; l <= j + 1; l ++ )
            if (g[k][l] == '1' && !flag)
            {
                res.EB(MP(k, l));
                g[k][l] = '0';
                flag = true;
            }
            else if (g[k][l] == '0' && cnt < 2)
            {
                res.EB(MP(k, l));
                g[k][l] = '1';
                cnt ++ ;
            }
}

void go2_3(int i, int j)
{
    bool flag = false;
    for (int k = i; k <= i + 1; k ++ )
        for (int l = j; l <= j + 1; l ++ )
            if (g[k][l] == '1' && !flag)
            {
                res.EB(MP(k, l));
                g[k][l] = '0';
                flag = true;
            }
            else if (g[k][l] == '0')
            {
                res.EB(MP(k, l));
                g[k][l] = '1';
            }
}

void go3_0(int i, int j)
{
    for (int k = i; k <= i + 1; k ++ )
        for (int l = j; l <= j + 1; l ++ )
            if (g[k][l] == '1')
            {
                res.EB(MP(k, l));
                g[k][l] = '0';
            }
}

void go4_1(int i, int j)
{
    int cnt = 0;
    for (int k = i; k <= i + 1; k ++ )
        for (int l = j; l <= j + 1; l ++ )
            if (cnt < 3 && g[k][l] == '1')
            {
                res.EB(MP(k, l));
                g[k][l] = '0';
                cnt ++ ;
            }
}

void op(int i, int j)
{
    int cnt = get(i, j);
    if (cnt == 0) return;
    else if (cnt == 1)
    {
        go1_2(i, j);
        go2_3(i, j);
        go3_0(i, j);
    }
    else if (cnt == 2)
    {
        go2_3(i, j);
        go3_0(i, j);
    }
    else if (cnt == 3) go3_0(i, j);
    else if (cnt == 4) 
    {
        go4_1(i, j);
        go1_2(i, j);
        go2_3(i, j);
        go3_0(i, j);
    }
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        res.clear();
        cin >> n >> m;
        for (int i = 1; i <= n; i ++ ) cin >> g[i] + 1;

        if (n % 2 == 0 && m % 2 == 0)
        {
            for (int i = 1; i <= n; i += 2)
                for (int j = 1; j <= m; j += 2)
                    op(i, j);
        }
        else if (n % 2 && m % 2 == 0)
        {
            for (int j = 1; j <= m; j += 2) op(n - 1, j);
            for (int i = 1; i <= n - 1; i += 2)
                for (int j = 1; j <= m; j += 2)
                    op(i, j);
        }
        else if (m % 2 && n % 2 == 0)
        {
            for (int i = 1; i <= n; i += 2) op(i, m - 1);
            for (int i = 1; i <= n; i += 2)
                for (int j = 1; j <= m - 1; j += 2)
                    op(i, j);
        }
        else if (n % 2 && m % 2)
        {
            op(n - 1, m - 1);
            for (int j = 1; j <= m; j += 2) op(n - 1, j);
            for (int i = 1; i <= n; i += 2) op(i, m - 1);
            for (int i = 1; i <= n; i += 2)
                for (int j = 1; j <= m - 1; j += 2)
                    op(i, j);
        }

        // for (int i = 1; i <= n; i ++ ) cout << g[i] + 1 << '\n';

        assert(SZ(res) / 3 <= n * m);
        cout << SZ(res) / 3 << '\n';
        for (int i = 0; i < SZ(res); i += 3)
        {
            cout << res[i].F << ' ' << res[i].S << ' ';
            cout << res[i + 1].F << ' ' << res[i + 1].S << ' ';
            cout << res[i + 2].F << ' ' << res[i + 2].S << '\n';
        }
    }
    return 0;
}

// GOOD LUCK!!!
