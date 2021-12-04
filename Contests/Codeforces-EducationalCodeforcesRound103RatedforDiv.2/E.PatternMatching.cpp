/**
 * Author: Daniel
 * Created Time: 2021-02-03 17:46:06
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
const int N = 100010, M = 2000010, P = 13331;

int n, m, k;
int h[N], e[M], ne[M], idx;
PA<string, int> p[N];
int q[N], d[N];
bool cycle;
map<ULL, PA<string, int>> mp;

void add_edge(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

ULL get_hash(string s)
{
    ULL res = 1;
    for (auto &c : s) res = res * P + (c - 'a');
    return res;
}

// read the question carefully!!!
int main()
{
    SOS;

    memset(h, -1, sizeof h);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> p[i].F;
        p[i].S = i;
        ULL code = get_hash(p[i].F);
        mp[code] = p[i];
    }

    for (int i = 1; i <= m; i ++ )
    {
        int mt;
        string s;
        cin >> s >> mt;
        bool flag = false;
        for (int bit = 0; bit < 1 << k; bit ++ )
        {
            string t(k, '_');
            for (int j = 0; j < k; j ++ )
                if ((bit >> j) & 1)
                    t[j] = s[j];

            ULL code = get_hash(t);
            if (mp.count(code))
            {
                if (mp[code].S == mt) flag = true;
                else 
                {
                    add_edge(mt, mp[code].S);
                    d[mp[code].S] += 1;
                }
            }
        }
        if (!flag)
        {
            cout << "NO\n";
            return 0;
        }
    }

    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i ++ )
        if (!d[i])
            q[ ++ tt] = i;
    while (hh <= tt)
    {
        int t = q[hh ++ ];
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if ( -- d[j] == 0) q[ ++ tt] = j;
        }
    }

    if (tt + 1 != n) cout << "NO\n";
    else
    {
        cout << "YES\n";
        for (int i = 0; i <= tt; i ++ )
        {
            cout << q[i];
            cout << " \n"[i == tt];
        }
    }
    return 0;
}

// GOOD LUCK!!!
