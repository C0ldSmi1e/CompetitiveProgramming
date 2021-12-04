/**
 * Author: Daniel
 * Created Time: 2021-06-19 11:20:02
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

template <typename A, typename B>
string to_string(pair<A, B> p);

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

template <typename A>
string to_string(priority_queue<A> heap)
{
    bool first = true;
    string res = "{";
    while ((int) heap.size())
    {
        if (!first) res += ", ";
        first = false;
        res += to_string(heap.top());
        heap.pop();
    }
    res += "}";
    return res;
}

template <typename A>
string to_string(priority_queue<A, vector<A>, greater<A> > heap)
{
    bool first = true;
    string res = "{";
    while ((int) heap.size())
    {
        if (!first) res += ", ";
        first = false;
        res += to_string(heap.top());
        heap.pop();
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

template <typename ... Ts>
string to_string(const Ts& ... ts)
{
    stringstream ss;
    const char* sep = "";
    ((static_cast<void>(ss << sep << ts), sep = ", "), ...);
    return ss.str();
}

template <typename... Args>
string to_string(const std::tuple<Args...> &t)
{
    string res = "(";
    apply([&](const auto&... ts) { res += to_string(ts...); }, t);
    res += ")";
    return res;
}

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
const int N = 400010, M = 1010;

int n, m;
int a[N];
int h[N], e[N], ne[N], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int scc_cnt, scc_size[N], id[N];
int din[N], dout[N];
VE<VI> pid, down;
int pcnt;
VS g;

void add_edge(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void tarjan(int u)
{
    low[u] = dfn[u] = ++ timestamp;
    stk[ ++ top] = u, in_stk[u] = true;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }
        else if (in_stk[j]) low[u] = min(low[u], dfn[j]);
    }
    if (low[u] == dfn[u])
    {
        int y;
        scc_cnt ++ ;
        do
        {
            y = stk[top -- ];
            in_stk[y] = false;
            id[y] = scc_cnt;
            scc_size[scc_cnt] ++ ;
        } while (y != u);
    }
}

// read the question carefully!!!
int main()
{
    SOS;

    memset(h, -1, sizeof h);
    cin >> n >> m;
    g.resize(n);
    for (auto &s : g) cin >> s;
    pid.resize(n);
    for (int i = 0; i < n; i ++ )
    {
        pid[i].resize(m);
        for (int j = 0; j < m; j ++ )
            if (g[i][j] == '#')
                pid[i][j] = ++ pcnt;
    }
    //for (int i = 0; i < n; i ++ )
    //    for (int j = 0; j < m; j ++ )
    //        cout << pid[i][j] << " \n"[j == m - 1];
    down.resize(n);
    for (int i = n - 1; i >= 0; i -- )
    {
        down[i].resize(m);
        for (int j = 0; j < m; j ++ )
            if (pid[i][j]) down[i][j] = pid[i][j];
            else if (i + 1 < n) down[i][j] = down[i + 1][j];
    }
    //for (int i = 0; i < n; i ++ )
    //    for (int j = 0; j < m; j ++ )
    //        cout << down[i][j] << " \n"[j == m - 1];
    for (int i = n - 1; i >= 0; i -- )
        for (int j = 0; j < m; j ++ )
        {
            int x = pid[i][j];
            if (!x) continue;
            if (i - 1 >= 0 && pid[i - 1][j]) add_edge(x, pid[i - 1][j]);
            if (i + 1 < n && down[i + 1][j]) add_edge(x, down[i + 1][j]);
            if (j - 1 >= 0 && down[i][j - 1]) add_edge(x, down[i][j - 1]);
            if (j + 1 < m && down[i][j + 1]) add_edge(x, down[i][j + 1]);
        }
    for (int i = 1; i <= pcnt; i ++ )
        if (!dfn[i])
            tarjan(i);
    //for (int u = 1; u <= pcnt; u ++ )
    //{
    //    debug(u);
    //    for (int i = h[u]; ~i; i = ne[i])
    //        debug(e[i]);
    //}
    //for (int i = 1; i <= pcnt; i ++ ) debug(i, id[i]);
    for (int u = 1; u <= pcnt; u ++ )
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            int a = id[u], b = id[j];
            if (a != b)
            {
                dout[a] ++ ;
                din[b] ++ ;
            }
        }
    debug(scc_cnt);
    int res = 0;
    for (int i = 1; i <= scc_cnt; i ++ )
        res += (int)(din[i] == 0);
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
