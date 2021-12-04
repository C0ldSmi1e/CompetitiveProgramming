/**
 * Author: Daniel
 * Created Time: 2021-05-06 19:49:02
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

mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());

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
const int N = 100010, M = 1010;
const LL INF = 4e18;

typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;

// read the question carefully!!!
int main()
{
    SOS;

    int n, m;
    LL w;
    cin >> n >> m >> w;
    VE<VI> id(n, VI(m));
    VI p, a(n * m);
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
        {
            id[i][j] = i * m + j;
            cin >> a[id[i][j]];
            if (a[id[i][j]] > 0) p.EB(id[i][j]);
        }
    VE<VE<PIL>> g(n * m);
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
        {
            if (a[id[i][j]] < 0) continue;
            for (int k = 0; k < 4; k ++ )
            {
                int tx = dx[k] + i;
                int ty = dy[k] + j;
                if (tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
                if (a[id[tx][ty]] < 0) continue;
                g[id[i][j]].EB(id[tx][ty], w);
            }
        }
    VL dist1(n * m, INF), dist2(n * m, INF);
    auto bfs = [&](int st, VL &dist)
    {
        dist[st] = 0;
        VI q;
        q.EB(st);
        for (int i = 0; i < SZ(q); i ++ )
        {
            auto t = q[i];
            for (auto &[u, w] : g[t])
            {
                if (dist[u] == INF)
                {
                    dist[u] = dist[t] + w;
                    q.EB(u);
                }
            }
        }
    };
    bfs(0, dist1);
    bfs(n * m - 1, dist2);
    LL res = dist1.back();
    int pn = SZ(p);
    LL t = INF;
    for (int i = 0; i < pn; i ++ ) t = min(t, dist2[p[i]] + a[p[i]]);
    for (int i = 0; i < pn; i ++ ) res = min(res, t + dist1[p[i]] + a[p[i]]);
    if (res == INF) res = -1;
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
