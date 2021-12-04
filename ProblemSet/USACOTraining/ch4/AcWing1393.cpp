/**
 * Author: Daniel
 * Created Time: 2020-12-28 07:28:04
**/

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
const int N = 1010, M = 1010, INF = 0x3f3f3f3f;

int n;
int p[N];
int f[N][N], g[N][N];
struct Edge
{
    int w;
    VI e[2];
} edge[M];

int find(int x)
{
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int get(int a, int b)
{
    for (int i = 0; i < 2; i ++ )
        for (auto &u : edge[b].e[i])
            if (a == u)
                return i * n + b;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        int s, len, n1, n2, id;
        cin >> s >> len >> n1 >> n2;
        edge[s].w = len;
        while (n1 -- )
        {
            cin >> id;
            edge[s].e[0].EB(id);
        }
        while (n2 -- )
        {
            cin >> id;
            edge[s].e[1].EB(id);
        }
    }

    for (int i = 0; i < N; i ++ ) p[i] = i;

    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j < 2; j ++ )
            for (auto &u : edge[i].e[j])
            {
                int a = j * n + i, b = get(i, u);
                p[find(a)] = find(b);
            }

    for (int i = 1; i <= 2 * n; i ++ )
        for (int j = 1; j <= 2 * n; j ++ )
            if (i == j) g[i][j] = 0;
            else g[i][j] = INF;
    
    for (int i = 1; i <= n; i ++ )
    {
        int a = find(i), b = find(i + n), c = edge[i].w;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    memcpy(f, g, sizeof f);
    int res = INF;
    for (int k = 1; k <= 2 * n; k ++ )
    {
        for (int i = 1; i < k; i ++ )
            for (int j = i + 1; j < k; j ++ )
                res = min((LL)res, (LL)f[i][j] + (LL)g[i][k] + (LL)g[j][k]);
        for (int i = 1; i <= 2 * n; i ++ )
            for (int j = 1; j <= 2 * n; j ++ )
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    }
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
