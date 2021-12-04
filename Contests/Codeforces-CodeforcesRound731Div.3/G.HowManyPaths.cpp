/**
 * Author: Daniel
 * Created Time: 2021-07-10 23:56:08
**/

// time-limit: 4000
// problem-url: https://codeforces.com/contest/1547/problem/G
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

vector<int> findSCC(const vector<vector<int>> g, int &id) {
  int n = static_cast<int>(g.size());
  int top = 0;
  vector<int> comp(n, -1), in(n, -1), out(n, -1), stk(n + 1, -1), order;
  function<int(int u)> tarjan = [&](int u) -> int {
    assert(top >= 0 && top <= n);
    stk[top++] = u;
    int low = in[u] = (int) order.size();
    order.push_back(u);
    for (auto &v : g[u]) {
      if (in[v] == -1) {
        low = min(low, tarjan(v));
        continue;
      }
      if (comp[v] == -1) {
        low = min(low, in[v]);
      }
    }
    if (low == in[u]) {
      while (stk[top] != u) {
        assert(top >= 0 && top <= n);
        comp[stk[--top]] = id;
      }
      id++;
    }
    out[u] = (int) order.size() - 1;
    return low;
  };
  for (int i = 0; i < n; i++) {
    if (in[i] == -1) {
      tarjan(i);
    }
  }
  return comp;
}

// read the question carefully!!!
int main()
{
    SOS;

    int T;
    cin >> T;
    while (T -- )
    {
        int n, m;
        cin >> n >> m;
        VE<VI> g(n);
        for (int i = 0; i < m; i ++ )
        {
            int a, b;
            cin >> a >> b;
            a -- , b -- ;
            g[a].EB(b);
        }
        int sn = 0;
        auto sg = findSCC(g, sn);
        VI sz(n);
        for (int i = 0; i < n; i ++ ) sz[sg[i]] ++ ;
        VI din(sn);
        VB selfloop(n, false);
        VE<VI> gg(sn);
        for (int u = 0; u < n; u ++ )
            for (auto &v : g[u])
            {
                int a = sg[u], b = sg[v];
                if (a == b) selfloop[a] = true;
                else
                {
                    gg[a].EB(b);
                    din[b] ++ ;
                }
            }
        debug(sn);
        debug(sg);
        VI q;
        for (int i = 0; i < sn; i ++ )
            if (!din[i])
                q.EB(i);
        VI res(n);
        for (int qq = 0; qq < SZ(q); qq ++ )
        {
            int t = q[qq];
            if (sg[0] == t) res[t] = 1;
            if (res[t] > 0 && (sz[t] > 1 || selfloop[t])) res[t] = -1;
            for (auto &u : gg[t])
            {
                if (res[u] == -1 || res[t] == -1) res[u] = -1;
                else res[u] = min(2, res[u] + res[t]);
                if ( -- din[u] == 0) q.EB(u);
            }
        }
        for (int i = 0; i < n; i ++ )
            cout << res[sg[i]] << " \n"[i == n - 1];
    }
    return 0;
}

// GOOD LUCK!!!
