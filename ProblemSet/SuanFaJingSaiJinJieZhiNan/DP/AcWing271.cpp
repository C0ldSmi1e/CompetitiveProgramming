/**
* Author: Name
* Created Time: 2020-11-18 21:21:25
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
const int N = 31, M = 1010;

int n;
int p[N];
LL f[N][N][N][N][N];

// read the question carefully!!!
int main()
{
    SOS;

    while (cin >> n && n)
    {
        memset(p, 0, sizeof p);
        memset(f, 0, sizeof f);

        for (int i = 1; i <= n; i ++ ) cin >> p[i];

        f[0][0][0][0][0] = 1;
        for (int a = 0; a <= p[1]; a ++ )
            for (int b = 0; b <= p[2]; b ++ )
                for (int c = 0; c <= p[3]; c ++ )
                    for (int d = 0; d <= p[4]; d ++ )
                        for (int e = 0; e <= p[5]; e ++ )
                            {
                                if (f[a][b][c][d][e] == 0LL) continue;

                                LL v = f[a][b][c][d][e];
                                if (a < p[1]) f[a + 1][b][c][d][e] += v;
                                if (b < a && b < p[2]) f[a][b + 1][c][d][e] += v;
                                if (c < b && c < p[3]) f[a][b][c + 1][d][e] += v;
                                if (d < c && d < p[4]) f[a][b][c][d + 1][e] += v;
                                if (e < d && e < p[5]) f[a][b][c][d][e + 1] += v;
                            }

        cout << f[p[1]][p[2]][p[3]][p[4]][p[5]] << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
