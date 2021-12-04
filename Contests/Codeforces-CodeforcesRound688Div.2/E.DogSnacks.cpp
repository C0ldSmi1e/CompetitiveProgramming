/**
 * Author: Daniel
 * Created Time: 2020-12-05 14:56:54
**/

// time-limit: 3000
#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define EB emplace_back
#define lowbit(x) (x & -x)
#define SZ(x) ((int)x.size())
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
const int N = 200010, M = 2 * N;

int T;
int n;
int h[N], e[M], ne[M], idx;
int res;

void add_edge(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int dfs(int u, int fa)
{
    VE<int> dist;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa) continue;

        dist.EB(dfs(j, u));
    }

    if (!SZ(dist)) return 0;

    sort(ALL(dist));
    if (u == 1) // root
    {
        res = max(res, dist.back() + 1);
        if (SZ(dist) > 1) res = max(res, dist[SZ(dist) - 2] + 2);
        return 0;
    }
    else
    {
        res = max(res, dist.back() + 2);
        return dist[0] + 1;
    }
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n;
        for (int i = 1; i <= n; i ++ ) h[i] = -1;

        for (int i = 0; i < n - 1; i ++ )
        {
            int a, b;
            cin >> a >> b;
            add_edge(a, b);
            add_edge(b, a);
        }

        res = 0;
        dfs(1, -1);
        cout << res << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
