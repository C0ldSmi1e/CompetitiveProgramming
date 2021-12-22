/**
 * Author: Daniel
 * Created Time: 2021-12-15 15:42:21
**/

// time-limit: 4500
// problem-url: https://codeforces.com/contest/1618/problem/G
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
typedef long double LD;
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
typedef vector<tuple<int, int, int> > VTIII;

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

template <typename... Args>
string to_string(const std::tuple<Args...> &t);

template <typename ... Ts>
string to_string(const Ts& ... ts);

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

LL sum;

class Dsu {
 public:
  vector<int> p, sz, cnt;
  VE<multiset<int>> A, B;
  int n;
  Dsu(int _n) {
    n = _n + 1;
    p.resize(n);
    A.resize(n);
    B.resize(n);
    cnt.resize(n);
    sz.assign(n, 1);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (sz[x] > sz[y]) {
      swap(x, y);
    }
    if (x != y) {
      cnt[y] += cnt[x];
      sz[y] += sz[x];
      for (auto &u : A[x]) {
        A[y].IS(u);
      }
      for (auto &u : B[x]) {
        B[y].IS(u);
      }
      A[x].clear();
      B[x].clear();
      while (SZ(A[y]) && SZ(B[y]) && *A[y].begin() < *prev(B[y].end())) {
        sum -= *A[y].begin();
        sum += *prev(B[y].end());
        A[y].IS(*prev(B[y].end()));
        B[y].IS(*A[y].begin());
        A[y].ER(A[y].begin());
        B[y].ER(prev(B[y].end()));
      }
      p[x] = y;
      return true;
    }
    return false;
  }
  inline int getSize(int x) {
    return sz[get(x)];
  }
};

// read the question carefully!!!
int main() {
  SOS;

  int n, m, k;
  cin >> n >> m >> k;
  VPII a(n + m);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = MP(x, 1);
    sum += x;
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    a[i + n] = MP(x, 0);
  }
  sort(ALL(a));
  Dsu d(n + m);
  for (int i = 0; i < n + m; i++) {
    auto [x, y] = a[i];
    if (y) {
      d.A[i].IS(x);
      d.cnt[i] = 1;
    } else {
      d.B[i].IS(x);
    }
  }
  VTIII op;
  for (int i = 0; i < n + m - 1; i++) {
    op.EB(MT(a[i + 1].F - a[i].F, 0, i));
  }
  VL res(k);
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    op.EB(x, 1, i);
  }
  sort(ALL(op));
  for (auto &[x, type, id] : op) {
    if (type == 0) {
      d.unite(id, id + 1);
    } else {
      res[id] = sum;
    }
  }
  for (auto &u : res) {
    cout << u << '\n';
  }
  return 0;
}

// GOOD LUCK!!!
