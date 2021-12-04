/**
 * Author: Daniel
 * Created Time: 2021-02-27 20:37:42
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
const int N = 1010, M = 1010, INF = 0x3f3f3f3f;

int n;
int g[N][N];
LL col[N][N][2], row[N][N][2];
LL f[N][N][2];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j ++ )
            if (s[j - 1] == 'B') g[i][j] = 1;
            else if (s[j - 1] == 'W') g[i][j] = 0;
            else g[i][j] = -1;
    }
    for (int i = 1; i <= n; i ++ )
        for (int j = 2; j <= n; j ++ )
        {
            int c = g[i][j];
            if (c != -1) 
            {
                row[i][j][c] = max(row[i][j - 1][c], row[i][j - 1][c ^ 1] + 1);
                row[i][j][c ^ 1] = -INF;
            }
            else
            {
                for (int c = 0; c <= 1; c ++ )
                    row[i][j][c] = max(row[i][j - 1][c], row[i][j - 1][c ^ 1] + 1);
            }
        }
    for (int i = 1; i <= n; i ++ )
    {
        row[i][1][g[i][1] ^ 1] = -INF;
        col[1][i][g[1][i] ^ 1] = -INF;
        
    }
    for (int j = 1; j <= n; j ++ )
        for (int i = 2; i <= n; i ++ )
        {
            int c = g[i][j];
            if (c != -1) 
            {
                col[i][j][c] = max(col[i - 1][j][c], col[i - 1][j][c ^ 1] + 1);
                col[i][j][c ^ 1] = -INF;
            }
            else
            {
                for (int c = 0; c <= 1; c ++ )
                    col[i][j][c] = max(col[i - 1][j][c], col[i - 1][j][c ^ 1] + 1);
            }
        }
    for (int i = 2; i <= n; i ++ )
        for (int j = 2; j <= n; j ++ )
        {
            int c = g[i][j];
            if (c != -1)
            {
                for (int c1 = 0; c1 <= 1; c1 ++ )
                    for (int c2 = 0; c2 <= 1; c2 ++ )
                        for (int c3 = 0; c3 <= 1; c3 ++ )
                        {
                            LL t = f[i - 1][j - 1][c1] + row[i][j - 1][c2] + col[i - 1][j][c3];
                            t += (int)(c2 ^ c) + (int)(c3 ^ c);
                            f[i][j][c] = max(f[i][j][c], t);
                        }
                f[i][j][c ^ 1] = -INF;
            }
            else
            {
                for (int c = 0; c <= 1; c ++ )
                    for (int c1 = 0; c1 <= 1; c1 ++ )
                        for (int c2 = 0; c2 <= 1; c2 ++ )
                            for (int c3 = 0; c3 <= 1; c3 ++ )
                            {
                                LL t = f[i - 1][j - 1][c1] + row[i][j - 1][c2] + col[i - 1][j][c3];
                                t += (int)(c2 ^ c) + (int)(c3 ^ c);
                                f[i][j][c] = max(f[i][j][c], t);
                            }
            }
        }
    debug(row[1][1][0]);
    debug(row[1][2][1]);
    LL res = 0;
    res = max(res, max(f[n][n][0], f[n][n][1]));
    res = max(res, max(col[n][n][0], col[n][n][1]));
    res = max(res, max(row[n][n][0], row[n][n][1]));
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
