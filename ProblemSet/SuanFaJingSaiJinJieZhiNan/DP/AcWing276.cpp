/**
* Author: Daniel
* Created Time: 2020-11-25 23:25:19
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
#define SZ(x) (int)(x.size())
#define MP(x, y) make_pair(x, y)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define SOS; ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

typedef long long LL;
typedef pair<int, int> PII;

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
const int N = 16, M = 100010;

int n, m, k;
int g[N][N];
int s[N][N];
int f[N][N * N][N][N][2][2];
struct Node
{
    int i, j, l, r, x, y;
} last[N][N * N][N][N][2][2];

int sum(int i, int l, int r)
{
    return s[i][r] - s[i][l - 1];
}

void print(Node t)
{
    if (!t.j) return;
    print(last[t.i][t.j][t.l][t.r][t.x][t.y]);
    for (int i = t.l; i <= t.r; i ++ )
        cout << t.i << ' ' << i << '\n';
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
        {
            cin >> g[i][j];
            s[i][j] = s[i][j - 1] + g[i][j];
        }

    memset(f, -0x3f, sizeof f);
    for (int i = 0; i <= n; i ++ )
        for (int l = 1; l <= m; l ++ )
            for (int r = l; r <= m; r ++ )
                f[i][0][l][r][0][0] = 0;

    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j <= k; j ++ )
            for (int l = 1; l <= m; l ++ )
                for (int r = l; r <= m; r ++ )
                {
                    int len = r - l + 1, v = sum(i, l, r);
                    if (j < len) continue;

                    // x = 0, y = 0
                    int &t1 = f[i][j][l][r][0][0];
                    for (int tl = l; tl <= r; tl ++ )
                        for (int tr = tl; tr <= r; tr ++ )
                        {
                            int val = f[i - 1][j - len][tl][tr][0][0] + v;
                            if (val > t1)
                            {
                                t1 = val;
                                last[i][j][l][r][0][0] = {i - 1, j - len, tl, tr, 0, 0};
                            }
                        }

                    // x = 0, y = 1
                    int &t2 = f[i][j][l][r][0][1];
                    for (int tl = l; tl <= r; tl ++ )
                        for (int tr = m; tr >= r; tr -- )
                            for (int ty = 0; ty < 2; ty ++ )
                            {
                                int val = f[i - 1][j - len][tl][tr][0][ty] + v;
                                if (val > t2)
                                {
                                    t2 = val;
                                    last[i][j][l][r][0][1] = {i - 1, j - len, tl, tr, 0, ty};
                                }
                            }

                    // x = 1, y = 0
                    int &t3 = f[i][j][l][r][1][0];
                    for (int tr = l; tr <= r; tr ++ )
                        for (int tl = 1; tl <= l; tl ++ )
                            for (int tx = 0; tx < 2; tx ++ )
                            {
                                int val = f[i - 1][j - len][tl][tr][tx][0] + v;
                                if (val > t3)
                                {
                                    t3 = val;
                                    last[i][j][l][r][1][0] = {i - 1, j - len, tl, tr, tx, 0};
                                }
                            }

                    // x = 1, y = 1
                    int &t4 = f[i][j][l][r][1][1];
                    for (int tl = 1; tl <= l; tl ++ )
                        for (int tr = m; tr >= r; tr -- )
                            for (int tx = 0; tx < 2; tx ++ )
                                for (int ty = 0; ty < 2; ty ++ )
                                {
                                    int val = f[i - 1][j - len][tl][tr][tx][ty] + v;
                                    if (val > t4)
                                    {
                                        t4 = val;
                                        last[i][j][l][r][1][1] = {i - 1, j - len, tl, tr, tx, ty};
                                    }
                                }
                }

    int res = 0;
    Node ans;
    for (int i = 1; i <= n; i ++ )
        for (int l = 1; l <= m; l ++ )
            for (int r = l; r <= m; r ++ )
                for (int x = 0; x < 2; x ++ )
                    for (int y = 0; y < 2; y ++ )
                        if (res < f[i][k][l][r][x][y])
                        {
                            res = f[i][k][l][r][x][y];
                            ans = {i, k, l, r, x, y};
                        }

    cout << "Oil : " << res << '\n';
    print(ans);
    return 0;
}

// GOOD LUCK!!!
