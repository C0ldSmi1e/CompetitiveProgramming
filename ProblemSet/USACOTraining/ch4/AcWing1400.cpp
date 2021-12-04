/**
 * Author: Daniel
 * Created Time: 2020-12-28 18:39:03
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
const int N = 1010, M = 1010;

int n, m;
int h[N], e[N], ne[N], idx;
int d[N];
char g[N][N];
bool used[N][N];
bool st[N];
string path;

void add_edge(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void check(char c, int t, int b, int l, int r)
{
    for (int i = l; i <= r; i ++ )
        if (g[t][i] != c)
        {
            int a = c - 'A' + 1, b = g[t][i] - 'A' + 1;
            if (!used[a][b])
            {
                d[b] ++ ;
                add_edge(a, b);
                used[a][b] = true;
            }
        }
    for (int i = l; i <= r; i ++ )
        if (g[b][i] != c)
        {
            int a = c - 'A' + 1, bb = g[b][i] - 'A' + 1;
            if (!used[a][bb])
            {
                d[bb] ++ ;
                add_edge(a, bb);
                used[a][bb] = true;
            }
        }
    for (int i = t; i <= b; i ++ )
        if (g[i][l] != c)
        {
            int a = c - 'A' + 1, b = g[i][l] - 'A' + 1;
            if (!used[a][b])
            {
                d[b] ++ ;
                add_edge(a, b);
                used[a][b] = true;
            }
        }
    for (int i = t; i <= b; i ++ )
        if (g[i][r] != c)
        {
            int a = c - 'A' + 1, b = g[i][r] - 'A' + 1;
            if (!used[a][b])
            {
                d[b] ++ ;
                add_edge(a, b);
                used[a][b] = true;
            }
        }
}

void dfs(string s)
{
    if (!SZ(s))
    {
        cout << path << '\n';
        return;
    }

    sort(ALL(s));
    for (int k = 0; k < SZ(s); k ++ )
    {
        int u = s[k] - 'A' + 1;
        string t = s.substr(0, k) + s.substr(k + 1);
        path += s[k];
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            if ( -- d[j] == 0)
                t += (char)(j - 1 + 'A');
        }
        dfs(t);
        path.PB();
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            d[j] ++ ;
        }
    }
}

// read the question carefully!!!
int main()
{
    SOS;

    memset(h, -1, sizeof h);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> g[i] + 1;

    for (char c = 'A'; c <= 'Z'; c ++ )
    {
        int maxx = 0, minx = N, maxy = 0, miny = N;
        bool flag = false;
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ )
                if (g[i][j] == c)
                {
                    maxx = max(maxx, i);
                    minx = min(minx, i);
                    maxy = max(maxy, j);
                    miny = min(miny, j);
                    flag = true;
                }

        if (flag)
        {
            st[c - 'A' + 1] = true;
            check(c, minx, maxx, miny, maxy);
        }
    }

    string s = "";
    for (int i = 1; i <= 26; i ++ )
        if (st[i] && !d[i])
            s += i - 1 + 'A';

    dfs(s);
    return 0;
}

// GOOD LUCK!!!
