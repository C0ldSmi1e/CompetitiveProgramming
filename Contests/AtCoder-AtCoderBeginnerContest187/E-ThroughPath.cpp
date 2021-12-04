/**
 * Author: Daniel
 * Created Time: 2021-01-02 20:41:11
**/

// time-limit: 2000
#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define ER erase
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
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef unsigned long long ULL;

template <typename A> using VE = vector<A>;
template <typename A> using USET = unordered_set<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A, typename B> using UMAP = unordered_map<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 200010, M = 2 * N;

int n, m;
int h[N], e[M], ne[M], idx;
int d[N];
LL f[N];
struct Edge
{
    int a, b;
} edge[N];

void dfs1(int u, int fa, int depth)
{
    d[u] = depth;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa) continue;
        
        dfs1(j, u, depth + 1);
    }
}

void dfs2(int u, int fa, LL val)
{
    f[u] += val;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa) continue;

        dfs2(j, u, f[u]);
    }
}

void add_edge(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

// read the question carefully!!!
int main()
{
    SOS;

    memset(h, -1, sizeof h);

    cin >> n;
    for (int i = 1; i <= n - 1; i ++ )
    {
        int a, b;
        cin >> a >> b;
        add_edge(a, b);
        add_edge(b, a);
        edge[i] = {a, b};
    }

    dfs1(1, -1, 1);

    cin >> m;
    while (m -- )
    {
        int t, ed, x;
        cin >> t >> ed >> x;
        int a = edge[ed].a, b = edge[ed].b;

        if (t == 1)
        {
            if (d[a] < d[b])
            {
                f[1] += x;
                f[b] -= x;
            }
            else f[a] += x;
        }
        else
        {
            if (d[b] < d[a])
            {
                f[1] += x;
                f[a] -= x;
            }
            else f[b] += x;
        }
    }

    dfs2(1, -1, 0);
    for (int i = 1; i <= n; i ++ ) cout << f[i] << '\n';
    return 0;
}

// GOOD LUCK!!!
