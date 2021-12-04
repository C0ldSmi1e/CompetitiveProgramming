/**
* Author: Daniel
* Created Time: 2020-11-23 13:04:29
**/

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
const int N = 15, M = 1010;

int n;
char pre[N][N], now[N][N], t[N][N], g[N][N];

void print(char g[][N])
{
    for (int i = 0; i < n; i ++ )
        cout << g[i] << '\n';
}

void mirror(char g[][N])
{
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            t[i][n - 1 - j] = g[i][j];
    memcpy(g, t, sizeof t);
}

void turn(char g[][N])
{
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            t[j][n - i - 1] = g[i][j];
    memcpy(g, t, sizeof t);
}

bool check(char a[][N], char b[][N])
{
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            if (a[i][j] != b[i][j])
                return false;
    return true;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> pre[i];
    for (int i = 0; i < n; i ++ ) cin >> now[i];

    memcpy(g, pre, sizeof g);

    // 90
    turn(g);
    if (check(g, now)) 
    {
        cout << "1\n";
        return 0;
    }

    // 180
    turn(g);
    if (check(g, now))
    {
        cout << "2\n";
        return 0;
    }

    // 270
    turn(g);
    if (check(g, now)) 
    {
        cout << "3\n";
        return 0;
    }

    // 360
    turn(g);
    // mirror
    mirror(g);
    if (check(g, now)) 
    {
        cout << "4\n";
        return 0;
    }
    
    // after mirror 90
    turn(g);
    if (check(g, now)) 
    {
        cout << "5\n";
        return 0;
    }

    // after mirror 180
    turn(g);
    if (check(g, now)) 
    {
        cout << "5\n";
        return 0;
    }

    // after mirror 270
    turn(g);
    if (check(g, now)) 
    {
        cout << "5\n";
        return 0;
    }


    if (check(pre, now)) cout << "6\n";
    else cout << "7\n";
    return 0;
}

// GOOD LUCK!!!
