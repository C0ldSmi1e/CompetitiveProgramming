/**
 * Author: Daniel
 * Created Time: 2021-09-23 22:28:58
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1574/problem/D
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
typedef tuple<int, int, int> TIII;
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

template <typename A, typename B>
string to_string(pair<A, B> p);

string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); } 

string to_string(const char c) { return to_string((string)"" + c); } 

string to_string(bool b) { return (b ? "true" : "false"); }

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
        res += ", ";
    } 
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A>
string to_string(priority_queue<A> heap) {
    bool first = true;
    string res = "{";
    while ((int) heap.size()) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(heap.top());
        heap.pop();
    }
    res += "}";
    return res;
}

template <typename A>
string to_string(priority_queue<A, vector<A>, greater<A> > heap) {
    bool first = true;
    string res = "{";
    while ((int) heap.size()) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(heap.top());
        heap.pop();
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

template <typename ... Ts>
string to_string(const Ts& ... ts) {
    stringstream ss;
    const char* sep = "";
    ((static_cast<void>(ss << sep << ts), sep = ", "), ...);
    return ss.str();
}

template <typename... Args>
string to_string(const std::tuple<Args...> &t) {
    string res = "(";
    apply([&](const auto&... ts) { res += to_string(ts...); }, t);
    res += ")";
    return res;
}

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

VI get(string &s)
{
    VI res;
    int cur = -1;
    for (auto &c : s)
        if (c == '#')
        {
            if (cur != -1) res.EB(cur);
            cur = 0;
        }
        else cur = cur * 10 + (int) (c - '0');
    if (cur != -1) res.EB(cur);
    return res;
}

string getStr(int x)
{
    if (x == 0) return "#0";
    string res;
    while (x)
    {
        res += (char) (x % 10 + '0');
        x /= 10;
    }
    reverse(ALL(res));
    res = '#' + res;
    return res;
}

vector<PA<int, string>> merge(vector<PA<int, string>> &a, vector<int> &b)
{
    int n = (int) a.size(), m = (int) b.size();
    assert(n + m > 0);
    sort(a.begin(), a.end());
    priority_queue<PA<int, string>> heap;
    for (int i = n - 1; i >= 0; i -- )
        heap.push(MP(a[i].F + b[m - 1], a[i].S + getStr(m - 1)));
    vector<PA<int, string>> res;
    for (LL i = 0; i < min((LL) N, (LL) n * m); i ++ )
    {
        auto [val, ids] = heap.top();
        heap.pop();
        res.emplace_back(val, ids);
        VI idx = get(ids);
        int last = idx.back();
        int len = SZ(ids);
        string remove = getStr(last);
        assert(len >= SZ(remove));
        if (last - 1 >= 0)
            heap.push(MP(val - b[last] + b[last - 1], ids.substr(0, len - SZ(remove)) + getStr(last - 1)));
    }
    return res;
}

// read the question carefully!!!
int main()
{
    SOS;

    int n;
    cin >> n;
    VI sz(n);
    VE<VI> a(n);
    for (int i = 0; i < n; i ++ )
    {
        cin >> sz[i];
        a[i].resize(sz[i]);
        for (auto &u : a[i]) cin >> u;
    }
    int m;
    cin >> m;
    set<string> bad;
    for (int i = 0; i < m; i ++ )
    {
        string s;
        for (int j = 0; j < n; j ++ )
        {
            int x;
            cin >> x;
            s += getStr(x - 1);
        }
        bad.IS(s);
    }
    debug(bad);
    VE<PA<int, string>> res(sz[0]);
    for (int i = sz[0] - 1; i >= 0; i -- )
        res[i] = MP(a[0][i], getStr(i));
    debug(res);
    for (int i = 1; i < n; i ++ )
        res = merge(res, a[i]);
    sort(RALL(res));
    debug(res);
    for (auto &[val, s] : res)
        if (!bad.count(s))
        {
            VI t = get(s);
            for (auto &u : t)
                cout << u + 1 << ' ';
            cout << '\n';
            break;
        }
    return 0;
}

// GOOD LUCK!!!
