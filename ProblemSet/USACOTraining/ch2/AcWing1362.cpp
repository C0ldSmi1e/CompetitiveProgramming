/**
 * Author: Daniel
 * Created Time: 2020-12-02 14:27:33
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
const int N = 1010, M = 1010;

int n, m;
int need[N], have[N][N];

int get(int x)
{
    int cnt = 0;
    while (x)
    {
        x -= lowbit(x);
        cnt ++ ;
    }
    return cnt;
}

bool check(int x)
{
    for (int i = 0; i < m; i ++ )
    {
        int tot = 0;
        for (int j = 0; j < n; j ++ )
            if ((x >> j) & 1)
                tot += have[j][i];
        if (tot < need[i]) return false;
    }
    return true;
}

bool cmp(int ans, int bit)
{
    for (int i = 0; i < n; i ++ )
        if (((ans >> i) & 1) == 0 && ((bit >> i) & 1) == 1) return true;
        else if (((ans >> i) & 1) == 1 && ((bit >> i) & 1) == 0) return false;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> m;
    for (int i = 0; i < m; i ++ ) cin >> need[i];

    cin >> n;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            cin >> have[i][j];

    int res = n, ans = -1;
    for (int bit = 0; bit < 1 << n; bit ++ )
    {
        int one = get(bit);
        if (one > res || !check(bit)) continue;

        if (ans == -1 || one < res || cmp(ans, bit))
        {
            res = one;
            ans = bit;
        }
    }

    cout << res << ' ';
    for (int i = 0; i < n; i ++ )
        if ((ans >> i) & 1)
            cout << i + 1 << ' ';
    cout << '\n';
    return 0;
}

// GOOD LUCK!!!
