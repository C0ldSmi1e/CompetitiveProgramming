/**
* Author: Name
* Created Time: 2020-11-21 00:54:55
**/

// time-limit: 2000
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
const int N = 200010, M = 32;

int n, a[N];
int son[N * M][2], idx;
int f[N * M];

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

void dfs(int p)
{
    if (son[p][0]) dfs(son[p][0]);
    if (son[p][1]) dfs(son[p][1]);
    f[p] = max(1, max(f[son[p][0]] + (son[p][1] > 0), f[son[p][1]] + (son[p][0] > 1)));
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 0; i < n; i ++ ) 
    {
        cin >> a[i];
        insert(a[i]);
    }

    dfs(0);
    cout << n - f[0] << '\n';
    return 0;
}

// GOOD LUCK!!!
