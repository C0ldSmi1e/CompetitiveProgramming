/**
 * Author: Daniel
 * Created Time: 2021-01-28 00:38:11
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
const int N = 110, M = 1010;
const double eps = 1e-6;

int n, m;
char g[N][N], f[N][N];
bool st[N][N];
double h[N];
int cnt;
VE<PII> q;

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void dfs(int x, int y)
{
    st[x][y] = true;
    q.EB(x, y);
    for (int i = 0; i < 8; i ++ )
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
        if (st[tx][ty] || g[tx][ty] != '1') continue;
        dfs(tx, ty);
    }
}

double calc(PII a, PII b)
{
    int dx = a.F - b.F;
    int dy = a.S - b.S;
    return sqrt(dx * dx + dy * dy);
}

char get()
{
    double sum = 0;
    for (int i = 0; i < SZ(q); i ++ )
        for (int j = i + 1; j < SZ(q); j ++ )
            sum += calc(q[i], q[j]);

    for (int i = 0; i < cnt; i ++ )
        if (fabs(sum - h[i]) < eps)
            return (char)(i + 'a');
    
    h[cnt ++ ] = sum;
    return (char)(cnt - 1 + 'a');
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> m >> n;
    for (int i = 1; i <= n; i ++ ) cin >> g[i] + 1;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            f[i][j] = '0';

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            if (!st[i][j] && g[i][j] == '1')
            {
                q.clear();
                dfs(i, j);
                char c = get();
                for (auto [x, y] : q) f[x][y] = c;
            }

    for (int i = 1; i <= n; i ++ ) cout << f[i] + 1 << '\n';
    return 0;
}

// GOOD LUCK!!!
