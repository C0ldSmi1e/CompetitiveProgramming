/**
*  Author: Daniel
*  Created Time: 2020-11-05 16:27:40
**/

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
const int N = 500010, M = 1010, INF = 0x3f3f3f3f;

int n, k;

// read the question carefully!!!
int main()
{
    IOS

    cin >> n >> k;

    V(int) a(n + 2), b(k + 2);

    a[0] = -INF, a[n + 1] = INF;
    b[0] = 0, b[k + 1] = n + 1;
    n += 2, k += 2;

    for (int i = 1; i < n - 1; i ++ )
    {
        cin >> a[i];
        a[i] -= i;
    }
    for (int i = 1; i < k - 1; i ++ ) cin >> b[i];

    int res = 0;
    for (int i = 0; i < k - 1; i ++ )
    {
        int l = b[i], r = b[i + 1];
        if (a[l] > a[r])
        {
            cout << "-1\n";
            return 0;
        }

        V(int) len;
        for (int j = l + 1; j < r; j ++ )
            if (a[j] >= a[l] && a[j] <= a[r])
            {
                auto pos = upper_bound(ALL(len), a[j]);
                if (pos == len.end()) len.EB(a[j]);
                else *pos = a[j];
            }
        res += r - l - 1 - SZ(len);
    }
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
