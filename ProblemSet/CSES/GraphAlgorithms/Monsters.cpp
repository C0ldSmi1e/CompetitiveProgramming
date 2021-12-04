/**
 * Author: Daniel
 * Created Time: 2021-07-23 10:54:32
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

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
        res += ", ";
    } 
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A>
string to_string(priority_queue<A> heap) {
    bool first = true;
    string res = "{";
    while ((int) heap.size()) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(heap.top());
        heap.pop();
    }
    res += "}";
    return res;
}

template <typename A>
string to_string(priority_queue<A, vector<A>, greater<A> > heap) {
    bool first = true;
    string res = "{";
    while ((int) heap.size()) {
        if (!first) {
            res += ", ";
        }
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
string to_string(const Ts& ... ts) {
    stringstream ss;
    const char* sep = "";
    ((static_cast<void>(ss << sep << ts), sep = ", "), ...);
    return ss.str();
}

template <typename... Args>
string to_string(const std::tuple<Args...> &t) {
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
    VS g(n);
    PII st;
    VPII mon;
    for (int i = 0; i < n; i ++ )
    {
        cin >> g[i];
        for (int j = 0; j < m; j ++ )
            if (g[i][j] == 'A') st = {i, j};
            else if (g[i][j] == 'M') mon.EB(i, j);
    }
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    VPII q{st};
    auto bfs = [&](VE<VI> &dist) -> VE<VPII>
    {
        VE<VPII> pre(n, VPII(m, MP(-1, -1)));
        for (int qq = 0; qq < SZ(q); qq ++ )
        {
            auto [x, y] = q[qq];
            for (int i = 0; i < 4; i ++ )
            {
                int tx = dx[i] + x;
                int ty = dy[i] + y;
                if (tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
                if (g[tx][ty] == '#' || dist[tx][ty] <= dist[x][y] + 1) continue;
                dist[tx][ty] = dist[x][y] + 1;
                pre[tx][ty] = {x, y};
                q.EB(tx, ty);
            }
        }
        return pre;
    };
    const int INF = 0x3f3f3f3f;
    VE<VI> dist1(n, VI(m, INF));
    dist1[st.F][st.S] = 0;
    auto pre = bfs(dist1);
    VE<VI> dist2(n, VI(m, INF));
    q.clear();
    for (auto &[x, y] : mon)
    {
        dist2[x][y] = 0;
        q.EB(x, y);
    }
    bfs(dist2);
    PII ed{-1, -1};
    for (int i = 0; i < n; i ++ )
    {
        if (dist1[i][0] < dist2[i][0]) ed = {i, 0};
        if (dist1[i][m - 1] < dist2[i][m - 1]) ed = {i, m - 1};
    }
    for (int j = 0; j < m; j ++ )
    {
        if (dist1[0][j] < dist2[0][j]) ed = {0, j};
        if (dist1[n - 1][j] < dist2[n - 1][j]) ed = {n - 1, j};
    }
    //for (int i = 0; i < n; i ++ )
    //    for (int j = 0; j < m; j ++ )
    //    {
    //        int d = dist1[i][j] == INF ? -1 : dist1[i][j];
    //        cout << d << " \n"[j == m - 1];
    //    }
    //cout << "---\n";
    //for (int i = 0; i < n; i ++ )
    //    for (int j = 0; j < m; j ++ )
    //    {
    //        int d = dist1[i][j] == INF ? -1 : dist2[i][j];
    //        cout << d << " \n"[j == m - 1];
    //    }
    auto get = [&](PII x, PII y) -> char
    {
        char c;
        if (x.F != y.F)
        {
            assert(x.S == y.S);
            if (x.F < y.F) c = 'D';
            else c = 'U';
        }
        if (x.S != y.S)
        {
            assert(x.F == y.F);
            if (x.S < y.S) c = 'R';
            else c = 'L';
        }
        return c;
    };
    if (ed.F != -1)
    {
        string path;
        PII cur = ed;
        while (true)
        {
            PII nxt = pre[cur.F][cur.S];
            if (nxt.F == -1) break;
            path += get(nxt, cur);
            cur = nxt;
        }
        reverse(ALL(path));
        cout << "YES\n" << SZ(path) << '\n' << path << '\n';
    }
    else cout << "NO\n";
    return 0;
}

// GOOD LUCK!!!
