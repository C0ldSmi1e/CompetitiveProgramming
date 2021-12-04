/**
 * Author: Daniel
 * Created Time: 2021-06-28 15:19:43
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
 
template <typename A>
class Lca {
 public:
  int n, root, lg;
  vector<A> dist;
  vector<int> depth;
  vector<vector<int> > fa;
 
  Lca(const vector<vector<int> > &g, int root) {
    n = static_cast<int>(g.size());
    lg = 32 - __builtin_clz(n);
    fa.resize(n);
    dist.resize(n);
    depth.resize(n);
    for (int i = 0; i < n; i++) {
      fa[i].resize(lg);
    }
    depth[root] = 0;
    fa[root][0] = root;
    vector<int> q;
    q.push_back(root);
    for (int qq = 0; qq < (int) q.size(); qq++) {
      int u = q[qq];
      for (int i = 1; i < lg; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
      }
      for (auto &v : g[u]) {
        if (v == fa[u][0]) {
          continue;
        }
        depth[v] = depth[u] + 1;
        dist[v] = dist[u] + 1;
        fa[v][0] = u;
        q.push_back(v);
      }
    }
  }
  int getLca(int a, int b) const {
    assert(a >= 0 && a < n && b >= 0 && b < n);
    if (depth[a] < depth[b]) {
      swap(a, b);
    }
    for (int k = lg - 1; k >= 0; k--) {
      if (depth[fa[a][k]] >= depth[b]) {
        a = fa[a][k];
      }
    }
    if (a == b) {
      return a;
    }
    for (int k = lg - 1; k >= 0; k--) {
      if (fa[a][k] != fa[b][k]) {
        a = fa[a][k];
        b = fa[b][k];
      }
    }
    return fa[a][0];
  }
  A getDist(int a, int b) const {
    assert(a >= 0 && a < n && b >= 0 && b < n);
    int anc = getLca(a, b);
    return dist[a] + dist[b] - 2 * dist[anc];
  }
};
 
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
const int N = 100010, M = 1010;
 
 
 
// read the question carefully!!!
int main()
{
    SOS;
 
    int n, m;
    cin >> n >> m;
    VE<VI> g(n);
    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b;
        cin >> a >> b;
        a -- , b -- ;
        g[a].EB(b);
        g[b].EB(a);
    }
    VI father(n, -2);
    function<void(int)> getFa = [&](int u)
    {
        for (auto &v : g[u])
            if (father[v] != -2) continue;
            else
            {
                father[v] = u;
                getFa(v);
            }
    };
    father[0] = -1;
    getFa(0);
    Lca<int> lca(g, 0);
    VI sum(n);
    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        a -- , b -- ;
        int anc = lca.getLca(a, b);
        if (anc == a)
        {
            sum[b] ++ ;
            if (father[a] != -1) sum[father[a]] -- ;
        }
        else if (anc == b)
        {
            sum[a] ++ ;
            if (father[b] != -1) sum[father[b]] -- ;
        }
        else 
        {
            sum[a] ++ , sum[b] ++ , sum[anc] -- ;
            if (father[anc] != -1) sum[father[anc]] -- ;
        }
    }
    debug(sum);
    function<void(int, int)> dfs = [&](int u, int fa)
    {
        for (auto &v : g[u])
        {
            if (v == fa) continue;
            dfs(v, u);
            sum[u] += sum[v];
        }
    };
    dfs(0, -1);
    for (auto &u : sum)
        cout << u << ' ';
    cout << '\n';
    return 0;
}
 
// GOOD LUCK!!!
