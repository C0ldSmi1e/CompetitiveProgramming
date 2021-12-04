/**
 * Author: Daniel
 * Created Time: 2021-11-01 18:12:26
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1604/problem/B
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

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 100010, M = 1010;

class SegmentTree {
 public:
    struct Node {
      // remember to set default value
      ...
      void apply(int l, int r, ... v) {
        // [l, r] is range of this node
        assert(l <= r);
        ...
      }
    };

    inline Node unite(const Node &a, const Node &b) const {
      Node res{};
      ...
      return res;
    }

    inline void pushdown(int u, int l, int r) {
      assert(u >= 0 && u < 2 * n && l <= r);
      int mid = (l + r) >> 1;
      int lson = u + 1, rson = u + ((mid - l + 1) << 1);
      // [l, r] is range of tr[u]
      // pushdown from u into lson and rson
      // remember to clear lazy tag in u
      ...
    /*
      if (tr[u].add != 0) {
        tr[lson].apply(l, mid, tr[u].add);
        tr[rson].apply(mid + 1, r, tr[u].add);
        tr[u].add = 0;
      }
    */
    }

    inline void pushup(int u, int lson, int rson) {
      tr[u] = unite(tr[lson], tr[rson]);
    }

    int n;
    vector<Node> tr;
    
    void build(int u, int l, int r) {
      if (l == r) {
        return;
      }
      int mid = (l + r) >> 1;
      int lson = u + 1, rson = u + ((mid - l + 1) << 1);
      build(lson, l, mid);
      build(rson, mid + 1, r);
      pushup(u, lson, rson);
    }

    template <typename T>
    void build(int u, int l, int r, const vector<T> &v) {
      if (l == r) {
        tr[u].apply(l, r, v[l]);
        return;
      }
      int mid = (l + r) >> 1;
      int lson = u + 1, rson = u + ((mid - l + 1) << 1);
      build(lson, l, mid, v);
      build(rson, mid + 1, r, v);
      pushup(u, lson, rson);
    }

    inline Node query(int u, int l, int r, int ql, int qr) {
      // [l, r] is range of tr[u]
      // [ql, qr] is range of query
      if (ql <= l && r <= qr) {
        return tr[u];
      }
      int mid = (l + r) >> 1;
      int lson = u + 1, rson = u + ((mid - l + 1) << 1);
      pushdown(u, l, r);
      Node res{};
      if (qr <= mid) {
        res = query(lson, l, mid, ql, qr);
      } else if (ql > mid) {
        res = query(rson, mid + 1, r, ql, qr);
      } else {
        res = unite(query(lson, l, mid, ql, qr), query(rson, mid + 1, r, ql, qr));
      }
      pushup(u, lson, rson);
      return res;
    }

    template <typename... T>
    inline void modify(int u, int l, int r, int ml, int mr, const T&... v) {
      // [l, r] is range of tr[u]
      // [ml, mr] is range of modification
      if (ml <= l && r <= mr) {
        tr[u].apply(l, r, v...);
        return;
      }
      int mid = (l + r) >> 1;
      int lson = u + 1, rson = u + ((mid - l + 1) << 1);
      pushdown(u, l, r);
      if (ml <= mid) {
        modify(lson, l, mid, ml, mr, v...);
      }
      if (mr > mid) {
         modify(rson, mid + 1, r, ml, mr, v...);
      }
      pushup(u, lson, rson);
    }

    SegmentTree(int _n) : n(_n) {
      assert(n > 0);
      tr.resize(2 * n - 1);
      build(0, 0, n - 1);
    }

    template <typename T>
    SegmentTree(const vector<T> &v) {
      n = (int) v.size();
      assert(n > 0);
      tr.resize(2 * n - 1);
      build(0, 0, n - 1, v);
    }

    inline Node query(int ql, int qr) {
      assert(ql >= 0 && ql <= qr && qr < n);
      return query(0, 0, n - 1, ql, qr);
    }

    inline Node query(int p) {
      assert(p >= 0 && p < n);
      return query(0, 0, n - 1, p, p);
    }

    template <typename... T>
    inline void modify(int ml, int mr, const T&... v) {
      assert(ml >= 0 && ml <= mr && mr < n);
      modify(0, 0, n - 1, ml, mr, v...);
    }
};

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
        if (n % 2 == 0) cout << "YES\n";
        else
        {
            bool flag = false;
            for (int i = 0; i < n - 1; i ++ )
                flag |= (a[i] >= a[i + 1]);
            cout << (flag ? "YES\n" : "NO\n");
        }
    }
    return 0;
}

// GOOD LUCK!!!
