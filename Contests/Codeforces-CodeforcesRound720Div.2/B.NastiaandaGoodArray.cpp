/**
 * Author: Daniel
 * Created Time: 2021-05-07 23:04:32
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1521/problem/B
#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define ER erase
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define MP make_pair
#define MT make_tuple
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define lowbit(x) (x & -x)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define SOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10)

typedef long long LL;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef pair<LL, LL> PLL;
typedef vector<string> VS;
typedef vector<double> VD;
typedef pair<int, int> PII;
typedef unsigned long long ULL;
typedef pair<double, double> PDD;
typedef vector<pair<LL, LL> > VPLL;
typedef vector<pair<int, int> > VPII;

template <typename A> using VE = vector<A>;
template <typename A> using USET = unordered_set<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A, typename B> using UMAP = unordered_map<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;

template <typename A> A MAX(const A &a) { return a; }
template <typename A> A MIN(const A &a) { return a; }
template <typename A> A MAX(const A *a, const A *b) { return *max_element(a, b); }
template <typename A> A MIN(const A *a, const A *b) { return *min_element(a, b); }
template <typename A, typename... B> A MAX(const A &a, const B&... b) { return max(a, MAX(b...)); }
template <typename A, typename... B> A MIN(const A &a, const B&... b) { return min(a, MIN(b...)); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> B MAX(A a, A b) { return *max_element(a, b); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> B MIN(A a, A b) { return *min_element(a, b); }

mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());

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
const int N = 100010, M = 1010;



// read the question carefully!!!
int main()
{
    SOS;

    int T;
    cin >> T;
    while (T -- )
    {
        int n;
        cin >> n;
        VI a(n);
        for (auto &u : a) cin >> u;
        if (n == 1)
        {
            cout << "0\n";
            continue;
        }
        VE<tuple<int, int, int, int>> res;
        if (a[1] > a[0]) 
        {
            res.EB(MT(0, 1, a[0], a[0] + 1));
            a[1] = a[0] + 1;
        }
        else 
        {
            res.EB(MT(0, 1, a[1], a[1] + 1));
            a[0] = a[1];
            a[1] = a[1] + 1;
        }
        for (int i = 2; i < n; i ++ )
        {
            if (a[i] > a[0])
            {
                res.EB(MT(0, i, a[0], a[i - 1] + 1));
                a[i] = a[i - 1] + 1;
            }
            else
            {
                res.EB(MT(0, i, a[i], a[i - 1] + 1));
                a[0] = a[i];
                a[i] = a[i - 1] + 1;
            }
        }
        if (__gcd(a[0], a[1]) > 1)
        {
            if (a[0] >= a[1])
            {
                res.EB(MT(0, 1, a[1] + 1, a[1]));
                a[0] = a[1] + 1;
            }
            else
            {
                if (n == 2)
                {
                    while (__gcd(a[0], a[1]) > 1) a[1] ++ ;
                }
                else
                {
                    while (__gcd(a[0], a[1]) > 1 || __gcd(a[1], a[2]) > 1) a[1] ++ ;
                }
                res.EB(MT(0, 1, a[0], a[1]));
            }
        }
        assert(SZ(res) <= n);
        debug(a);
        cout << SZ(res) << '\n';
        for (auto &[i, j, x, y] : res)
            cout << i + 1 << ' ' << j + 1 << ' ' << x << ' ' << y << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
