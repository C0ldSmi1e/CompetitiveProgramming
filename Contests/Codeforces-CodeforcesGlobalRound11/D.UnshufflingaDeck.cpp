/**
*  Author: Daniel
*  Created Time: 2020-11-01 13:50:50
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
const int N = 55, M = 1010;

int n;

// read the question carefully!!!
int main()
{
    IOS

    cin >> n;
    V(int) a(n);
    for (auto &u : a) cin >> u;

    V(V(int)) res;

    while (true)
    {
        int j = -1, i = -1;
        map<int, int> h;
        bool flag = true;
        for (int k = 0; k < n; k ++ )
        {
            if (h.count(a[k] + 1))
            {
                i = k;
                j = h[a[k] + 1];
                flag = false;
                break;
            }
            h[a[k]] = k;
        }
        if (flag) break;

        V(int) len(n + 1);
        for (int i = 0; i < n; i ++ )
        {
            int j = i;
            while (j + 1 < n && a[j + 1] == a[j] + 1) j ++ ;
            for (int k = j; k >= i; k -- ) len[a[k]] = j - k + 1;
            i = j;
        }

        V(int) ans;
        int len1 = j, len2 = len[a[j]], len3 = i - j - len[a[j]] + 1, len4 = n - i - 1;
        if (len1) ans.EB(len1);
        ans.EB(len2);
        ans.EB(len3);
        if (len4) ans.EB(len4);

        V(int) t(n);
        int tj = 0, ti = n - len4;
        for (int cnt = 0; cnt < len4; cnt ++ ) t[tj ++ ] = a[ti ++ ];
        ti = n - len4 - len3;
        for (int cnt = 0; cnt < len3; cnt ++ ) t[tj ++ ] = a[ti ++ ];
        ti = len1;
        for (int cnt = 0; cnt < len2; cnt ++ ) t[tj ++ ] = a[ti ++ ];
        ti = 0;
        for (int cnt = 0; cnt < len1; cnt ++ ) t[tj ++ ] = a[ti ++ ];

        a.swap(t);
        res.EB(ans);
    }

    cout << SZ(res) << '\n';
    for (auto &u : res)
    {
        cout << SZ(u) << ' ';
        for (auto &v : u) cout << v << ' ';
        cout << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
