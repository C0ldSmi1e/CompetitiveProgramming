/**
* Author: Daniel
* Created Time: 2020-11-26 11:00:00
**/

// time-limit: 2000
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
const int N = 200010, M = 18;

int T;
int n, a[N];
int pre[N], suf[N];
int f[N][M], LOG2[N];

void init()
{
    for (int j = 0; j < M; j ++ )
        for (int i = 1; i + (1 << j) - 1 <= n; i ++ )
            if (!j) f[i][j] = a[i];
            else f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r)
{
    int len = r - l + 1;
    int k = LOG2[len];
    return min(f[l][k], f[r - (1 << k) + 1][k]);
}

// read the question carefully!!!
int main()
{
    SOS;

    for (int i = 2; i < N; i ++ ) LOG2[i] = LOG2[i / 2] + 1;

    cin >> T;
    while (T -- )
    {
        cin >> n;
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        init();

        pre[1] = a[1], suf[n] = a[n];
        for (int i = 2; i <= n; i ++ ) pre[i] = max(pre[i - 1], a[i]);
        for (int i = n - 1; i; i -- ) suf[i] = max(suf[i + 1], a[i]);

        bool flag = false;
        for (int i = n - 1; i >= 2; i -- )
        {
            int val = suf[i + 1];
            int st = lower_bound(pre + 1, pre + i + 1, val) - pre;
            int ed = upper_bound(pre + 1, pre + i + 1, val) - pre;

            if (st >= ed || st + 1 == ed && ed > i) continue;

            int l = st + 1, r = ed;
            while (l < r)
            {
                int mid = l + r >> 1;
                if (query(mid, i) >= val) r = mid;
                else l = mid + 1;
            }

            if (query(r, i) == val)
            {
                cout << "YES\n";
                cout << r - 1 << ' ' << i - r + 1 << ' ' << n - i << '\n';
                flag = true;
                break;
            }
        }

        if (!flag) cout << "NO\n";
    }
    return 0;
}

// GOOD LUCK!!!
