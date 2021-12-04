/**
 * Author: Daniel
 * Created Time: 2021-10-15 10:49:12
**/

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
const int N = 1010, M = 1010;



template <typename T>
class Fenwick {
 public:
  vector<vector<T> > fenw;
  int n, m;
  Fenwick(int _n, int _m) : n(_n), m(_m) {
    fenw.resize(n + 1);
    for (int i = 0; i < n; i++) {
      fenw[i].resize(m);
    }
  }
  // Change a[x][y] to v
  inline void add(int x, int y, T v) {
    assert(x >= 0 && x < n && y >= 0 && y < m);
    for (int i = x + 1; i <= n; i += lowbit(i)) {
      for (int j = y + 1; j <= m; j += lowbit(j)) {
        fenw[i - 1][j - 1] += v;
      }
    }
  }
  inline T get(int x, int y) {
    assert(x >= 0 && x < n && y >= 0 && y < m);
    T res{};
    for (int i = x + 1; i >= 1; i -= lowbit(i)) {
      for (int j = y + 1; j >= 1; j -= lowbit(j)) {
        res += fenw[i - 1][j - 1];
      }
    }
    return res;
  }
  // ask for [x1, x2] and [y1, y2]
  inline T get(int x1, int y1, int x2, int y2) {
    assert (x1 <= x2 && y1 <= y1);
    assert(x1 >= 0 && x1 < n && x2 >= 0 && x2 < n);
    assert(y1 >= 0 && y1 < m && y2 >= 0 && y2 < m);
    T res = get(x2, y2);
    if (x1 - 1 >= 0) {
      res -= get(x1 - 1, y2);
    }
    if (y1 - 1 >= 0) {
      res -= get(x2, y1 - 1);
    }
    if (x1 - 1 >= 0 && y1 - 1 >= 0) {
      res += get(x1 - 1, y1 - 1);
    }
    return res;
  }
};
// struct node {
//   int a = ...; // don't forget to set default value
//   inline void operator += (node &other) {
//     ...
//   }
// };

// read the question carefully!!!
int main()
{
    SOS;

    int n, q;
    cin >> n >> q;
    int m = n;
    VE<VI> a(n, VI(m));
    for (int i = 0; i < n; i ++ )
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j ++ )
            a[i][j] = (int) (s[j] == '*');
    }
    Fenwick<int> fen(n, m);
    fen.add(0, 0, a[0][0]);
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            fen.add(i, j, a[i][j]);
    while (q -- )
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, y;
            cin >> x >> y;
            x -- , y -- ;
            fen.add(x, y, -a[x][y]);
            a[x][y] ^= 1;
            fen.add(x, y, a[x][y]);
        }
        else
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1 -- , y1 -- , x2 -- , y2 -- ;
            cout << fen.get(x1, y1, x2, y2) << '\n';
        }
    }
    return 0;
}

// GOOD LUCK!!!
