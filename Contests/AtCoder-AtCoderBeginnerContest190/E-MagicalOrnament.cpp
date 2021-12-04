/**
 * Author: Daniel
 * Created Time: 2021-02-24 19:36:26
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

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); } 

string to_string(const char c) { return to_string((string)"" + c); } 

string to_string(bool b) { return (b ? "true" : "false"); }

string to_string(vector<bool> v) 
{
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) 
    {
        if (!first) res += ", ";
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v)
{
    string res = "";
    for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
    return res;
}

template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; }

void debug_out() { cout << '\n'; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cout << " " << to_string(H); debug_out(T...); }

#ifdef LOCAL
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 100010, M = 18, INF = 0x3f3f3f3f;

int n, m, k;
int h[N], e[2 * N], ne[2 * N], idx;
int c[N];
int dist[M][N];
int f[M][1 << M];
int q[N];

void add_edge(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

// read the question carefully!!!
int main()
{
    SOS;

    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        cin >> a >> b;
        add_edge(a, b);
        add_edge(b, a);
    }
    cin >> k;
    for (int i = 0; i < k; i ++ ) cin >> c[i];
    memset(dist, 0x3f, sizeof dist);
    for (int i = 0; i < k; i ++ )
    {
        int hh = 0, tt = -1;
        q[ ++ tt] = c[i];
        dist[i][c[i]] = 0;
        while (hh <= tt)
        {
            auto t = q[hh ++ ];
            for (int j = h[t]; ~j; j = ne[j])
            {
                int k = e[j];
                if (dist[i][k] == INF)
                {
                    dist[i][k] = dist[i][t] + 1;
                    q[ ++ tt] = k;
                }
            }
        }
    }
    //for (int i = 0; i < k; i ++ )
    //    for (int j = 1; j <= n; j ++ )
    //    {
    //        cout << dist[i][j];
    //        cout << " \n"[j == n];
    //    }
    memset(f, 0x3f, sizeof f);
    for (int i = 0; i < k; i ++ ) f[i][1 << i] = 1;
    for (int mask = 0; mask < 1 << k; mask ++ )
        for (int i = 0; i < k; i ++ )
        {
            if (f[i][mask] == INF) continue;
            for (int j = 0; j < k; j ++ )
                if (((mask >> j) & 1) == 0)
                    f[j][mask | (1 << j)] = min(f[j][mask | (1 << j)], f[i][mask] + dist[j][c[i]]);
        }
    int res = INF;
    for (int i = 0; i < k; i ++ ) res = min(res, f[i][(1 << k) - 1]);
    if (res == INF) cout << "-1\n";
    else cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
