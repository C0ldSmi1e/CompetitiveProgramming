/**
 * Author: Daniel
 * Created Time: 2020-12-11 09:14:01
**/

#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
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
typedef pair<int, int> PII;
typedef unsigned long long ULL;

template <typename A> using VE = vector<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
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
const int N = 1010, M = 1000010;

int n, m;
int f[2][N][N];
string g[N];
PII q[M];

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

bool check(int x, int y, int t)
{
    return g[x * 2 - 1 + dx[t]][y * 2 - 1 + dy[t]] == ' ';
}

void bfs(int x, int y, int k)
{
    memset(f[k], -1, sizeof f[k]);
    int hh = 0, tt = -1;
    q[ ++ tt] = MP(x, y);
    f[k][x][y] = 1;

    while (hh <= tt)
    {
        auto t = q[hh ++ ];

        for (int i = 0; i < 4; i ++ )
        {
            int tx = t.F + dx[i];
            int ty = t.S + dy[i];

            if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
            if (f[k][tx][ty] != -1 || !check(t.F, t.S, i)) continue;

            f[k][tx][ty] = f[k][t.F][t.S] + 1;
            q[ ++ tt] = MP(tx, ty);
        }
    }
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> m >> n;
    getline(cin, g[0]);
    for (int i = 0; i < 2 * n + 1; i ++ ) getline(cin, g[i]);

    int k = 0;
    for (int i = 1; i <= n; i ++ )
    {
        if (check(i, 1, 3)) bfs(i, 1, k), k ++ ;
        if (check(i, m, 1)) bfs(i, m, k), k ++ ;
    }
    for (int i = 1; i <= m; i ++ )
    {
        if (check(1, i, 0)) bfs(1, i, k), k ++ ;
        if (check(n, i, 2)) bfs(n, i, k), k ++ ;
    }

    int res = 0;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            res = max(res, min(f[0][i][j], f[1][i][j]));
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
