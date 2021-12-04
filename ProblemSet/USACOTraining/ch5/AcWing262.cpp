/**
 * Author: Daniel
 * Created Time: 2021-01-30 14:38:55
**/

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
const int N = 100010, M = 1010, INF = 0x3f3f3f3f;

int n;
struct Rec
{
    PII a, b;
} rec[N];

LL get()
{
    VI xs;
    for (int i = 0; i < n; i ++ )
    {
        auto &r = rec[i];
        xs.EB(r.a.F);
        xs.EB(r.b.F);
    }

    sort(ALL(xs));

    LL res = 0;
    VE<PII> seg;
    for (int i = 0; i < SZ(xs) - 1; i ++ )
    {
        seg.clear();
        int l = xs[i], r = xs[i + 1];
        for (int j = 0; j < n; j ++ )
        {
            if (rec[j].a.F <= l && rec[j].b.F >= r)
                seg.EB(rec[j].a.S, rec[j].b.S);
        }
        sort(ALL(seg));

        int cnt = 0;
        l = r = -INF;
        for (auto [x, y] : seg)
            if (x > r)
            {
                cnt ++ ;
                l = x, r = y;
            }
            else r = max(r, y);

        res += 2LL * cnt * (xs[i + 1] - xs[i]);
    }
    return res;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        PII a, b;
        cin >> a.F >> a.S >> b.F >> b.S;
        rec[i] = {a, b};
    }

    LL res = get();
    for (int i = 0; i < n; i ++ )
    {
        auto &r = rec[i];
        swap(r.a.F, r.a.S);
        swap(r.b.F, r.b.S);
    }
    res += get();
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
