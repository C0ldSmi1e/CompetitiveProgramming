/**
*  Author: Daniel
*  Created Time: 2020-11-01 21:16:01
**/

// time-limit: 2000
#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define V(x) vector<x>
#define EB emplace_back
#define PII P(int, int)
#define lowbit(x) (x & -x)
#define P(x, y) pair<x, y>
#define SZ(x) (int)(x.size())
#define MP(x, y) make_pair(x, y)
#define HEAP(x) priority_queue<x>
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define RHEAP(x) priority_queue<x, vector<x>, greater<x> >
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

typedef long long LL;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) { return '"' + s + '"'; }
 
string to_string(const char* s) { return to_string((string) s); } 
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

// check the limitation!!!
const int N = 200010, M = 1010;

int n, m;
int h[N], w[N];
LL l[N], r[N];
LL s[N];

// read the question carefully!!!
int main()
{
    IOS

    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> h[i];
    for (int i = 1; i <= m; i ++ ) cin >> w[i];
    sort(h + 1, h + 1 + n);
    sort(w + 1, w + 1 + m);

    for (int i = 3; i <= n; i += 2) l[i] = l[i - 2] + h[i - 1] - h[i - 2];
    for (int i = n - 2; i >= 1; i -= 2) r[i] = r[i + 2] + h[i + 2] - h[i + 1];

    for (int i = 1; i <= n; i ++ )
        if (i & 1) s[i] = l[i] + r[i];
    
    LL res = 4e18;
    for (int i = 1; i <= m; i ++ )
    {
        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (h[mid] >= w[i]) r = mid;
            else l = mid + 1;
        }
        if (r & 1) res = min(res, s[r] + abs(h[r] - w[i]));
        else 
        {
            res = min(res, s[r + 1] + abs(h[r + 1] - w[i]));
            res = min(res, s[r - 1] + abs(h[r - 1] - w[i]));
        }
    }
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
