/**
 * Author: Daniel
 * Created Time: 2021-02-05 14:58:55
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
#define SOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10)

typedef long long LL;
typedef vector<LL> VL;
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
const int N = 100010, M = 1010;

int n, m;
int h[N], e[N], ne[N], idx;
int dfn[N], low[N], timestamp;
int root, ans;

void add_edge(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++ timestamp;
    int cnt = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
            if (low[j] >= dfn[u]) cnt ++ ;
        }
        else low[u] = min(low[u], dfn[j]);
    }
    if (u != root) cnt ++ ;
    ans = max(ans, cnt);
}

// read the question carefully!!!
int main()
{
    SOS;

    while (cin >> n >> m, n || m)
    {
        idx = timestamp = ans = 0;
        memset(h, -1, sizeof h);
        memset(dfn, 0, sizeof dfn);

        while (m -- )
        {
            int a, b;
            cin >> a >> b;
            add_edge(a, b);
            add_edge(b, a);
        }

        int cnt = 0;
        for (root = 0; root < n; root ++ )
            if (!dfn[root])
            {
                cnt ++ ;
                tarjan(root);
            }
        
        cout << cnt - 1 + ans << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
