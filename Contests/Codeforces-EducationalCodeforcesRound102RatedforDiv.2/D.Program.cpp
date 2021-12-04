/**
 * Author: Daniel
 * Created Time: 2021-01-28 01:11:00
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
const int N = 200010, M = 18;

int T;
int n, m;
int a[N];
int f1[N][M], f2[N][M];
int LOG2[N];

void init(int n)
{
    for (int i = 2; i <= n * 2; i ++ ) LOG2[i] = LOG2[i / 2] + 1;
    for (int j = 0; j < M; j ++ )
        for (int i = 1; i + (1 << j) - 1 <= n; i ++ )
            if (!j) f1[i][j] = f2[i][j] = a[i];
            else 
            {
                f1[i][j] = max(f1[i][j - 1], f1[i + (1 << (j - 1))][j - 1]);
                f2[i][j] = min(f2[i][j - 1], f2[i + (1 << (j - 1))][j - 1]);
            }
}

int query_max(int l, int r)
{
    int len = r - l + 1;
    if (len <= 0) return 0;
    int k = LOG2[len];
    return max(f1[l][k], f1[r - (1 << k) + 1][k]);
}

int query_min(int l, int r)
{
    int len = r - l + 1;
    if (len <= 0) return 0;
    int k = LOG2[len];
    return min(f2[l][k], f2[r - (1 << k) + 1][k]);
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i ++ )
        {
            char c;
            cin >> c;
            if (c == '-') a[i] = -1;
            else a[i] = 1;
        }

        for (int i = 1; i <= n; i ++ ) a[i] += a[i - 1];
        init(n);
        while (m -- )
        {
            int l, r;
            cin >> l >> r;
            int cnt = 1;
            int left_max = query_max(1, l - 1), left_min = query_min(1, l - 1);
            int right_max = query_max(r + 1, n) - a[r] + a[l - 1], right_min = query_min(r + 1, n) - a[r] + a[l - 1];
            if (l == 1) left_max = left_min = 0;
            if (r == n) right_max = right_min = 0;
            int maxa = max(left_max, right_max);
            int mina = min(left_min, right_min);
            if (maxa > 0) cnt += maxa;
            if (mina < 0) cnt += -mina;
            cout << cnt << '\n';
        }
    }
    return 0;
}

// GOOD LUCK!!!
