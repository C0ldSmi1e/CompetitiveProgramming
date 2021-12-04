/**
 * Author: Daniel
 * Created Time: 2021-06-21 09:03:43
**/

#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define ER erase
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define MP make_pair
#define MT make_tuple
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define lowbit(x) (x & -x)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define SOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10)

typedef long long LL;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef pair<LL, LL> PLL;
typedef vector<string> VS;
typedef vector<double> VD;
typedef pair<int, int> PII;
typedef unsigned long long ULL;
typedef pair<double, double> PDD;
typedef tuple<int, int, int> TIII;
typedef vector<pair<LL, LL> > VPLL;
typedef vector<pair<int, int> > VPII;

template <typename A> using VE = vector<A>;
template <typename A> using USET = unordered_set<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A, typename B> using UMAP = unordered_map<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;

template <typename A> A MAX(const A &a) { return a; }
template <typename A> A MIN(const A &a) { return a; }
template <typename A> A MAX(const A *a, const A *b) { return *max_element(a, b); }
template <typename A> A MIN(const A *a, const A *b) { return *min_element(a, b); }
template <typename A, typename... B> A MAX(const A &a, const B&... b) { return max(a, MAX(b...)); }
template <typename A, typename... B> A MIN(const A &a, const B&... b) { return min(a, MIN(b...)); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> B MAX(A a, A b) { return *max_element(a, b); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> B MIN(A a, A b) { return *min_element(a, b); }

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 200010, M = 2 * N, K = 20;

int n, m;
int h[N], e[M], w[M], ne[M], idx;
int depth[N], f[N][K];
int dist[N];

void add_edge(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void bfs(int root)
{
    memset(dist, -1, sizeof dist);
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0;
    depth[root] = 1;
    dist[root] = 0;
    VI q;
    q.EB(root);
    for (int qq = 0; qq < SZ(q); qq ++ )
    {
        int t = q[qq];
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] != -1) continue;
            dist[j] = dist[t] + w[i];
            depth[j] = depth[t] + 1;
            f[j][0] = t;
            for (int k = 1; k < K; k ++ )
                f[j][k] = f[f[j][k - 1]][k - 1];
            q.EB(j);
        }
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b]) swap(a, b);
    for (int k = K - 1; k >= 0; k -- )
        if (depth[f[a][k]] >= depth[b])
            a = f[a][k];
    if (a == b) return a;
    for (int k = K - 1; k >= 0; k -- )
        if (f[a][k] != f[b][k])
        {
            a = f[a][k];
            b = f[b][k];
        }
    return f[a][0];
}

int get_dist(int a, int b)
{
    int ac = lca(a, b);
    return dist[a] + dist[b] - 2 * dist[ac];
}

// read the question carefully!!!
int main()
{
    SOS;

    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b;
        cin >> a >> b;
        add_edge(a, b, 1);
        add_edge(b, a, 1);
    }
    bfs(1);
    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        cout << get_dist(a, b) << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
