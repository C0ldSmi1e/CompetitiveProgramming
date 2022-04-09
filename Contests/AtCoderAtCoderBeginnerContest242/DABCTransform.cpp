/**
 * Author: Daniel
 * Created Time: 2022-03-08 13:15:13
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc242/tasks/abc242_d
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
#define SOS(x) ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(x)

typedef long long LL;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef long double LD;
typedef vector<char> VC;
typedef vector<bool> VB;
typedef pair<LL, LL> PLL;
typedef vector<string> VS;
typedef vector<double> VD;
typedef pair<int, int> PII;
typedef unsigned long long ULL;
typedef pair<double, double> PDD;
typedef tuple<int, int, int> TIII;
typedef vector<pair<LL, LL>> VPLL;
typedef vector<pair<int, int>> VPII;
typedef vector<tuple<int, int, int>> VTIII;

template <typename A> using VE = vector<A>;
template <typename A> using USET = unordered_set<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A, typename B> using UMAP = unordered_map<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A>>;

template <typename A> A MAX(const A &a) { return a; }
template <typename A> A MIN(const A &a) { return a; }
template <typename A> A MAX(const A *a, const A *b) { return *max_element(a, b); }
template <typename A> A MIN(const A *a, const A *b) { return *min_element(a, b); }
template <typename A> int CNT(const A *a, const A *b, const A &v) { return int(count(a, b, v)); }
template <typename A, typename... B> A MAX(const A &a, const B&... b) { return max(a, MAX(b...)); }
template <typename A, typename... B> A MIN(const A &a, const B&... b) { return min(a, MIN(b...)); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> B MAX(const A &a, const A &b) { return *max_element(a, b); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> B MIN(const A &a, const A &b) { return *min_element(a, b); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> int CNT(const A &a, const A &b, const B &v) { return int(count(a, b, v)); }

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename ...Args>
string to_string(const std::tuple<Args...> &t);

template <typename ...Ts>
string to_string(const Ts &...ts);

string to_string(const string &s) { return '"' + s + '"'; }

string to_string(const char *s) { return to_string((string) s); } 

string to_string(const char c) { return to_string((string) "" + c); } 

string to_string(bool b) { return (b ? "true" : "false"); }

string to_string(_Bit_reference b) { return (b ? "true" : "flase"); }

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
string to_string(priority_queue<A, vector<A>, greater<A>> heap) {
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

template <typename ...Ts>
string to_string(const Ts &...ts) {
  stringstream ss;
  const char* sep = "";
  ((static_cast<void>(ss << sep << ts), sep = ", "), ...);
  return ss.str();
}

template <typename ...Args>
string to_string(const std::tuple<Args...> &t) {
  string res = "(";
  apply([&](const auto &...ts) { res += to_string(ts...); }, t);
  res += ")";
  return res;
}

void debug_out() { cout << '\n'; }

template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T) { cout << " " << to_string(H); debug_out(T...); }

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
int main() {
  SOS(10);

  string s;
  cin >> s;
  map<char, string> mp;
  mp['A'] = "BC";
  mp['B'] = "CA";
  mp['C'] = "AB";
  int q;
  cin >> q;
  while (q--) {
    LL t, k;
    cin >> t >> k;
    int i = 0;
    if (t > 62) {
      i = 0;
    } else {
      LL cur = 0;
      while (cur + (1LL << t) < k) {
        ++i;
        cur += (1LL << t);
      }
      k -= i * (1LL << t);
    }
    char c = s[i];
    // find c turns t times the kth character
    LL least = 0;
    while ((1LL << least) < k) {
      ++least;
    }
    assert(least <= t);
    // find turns least times the kth character
    int cd = (int) (c - 'A');
    int dd = (int) ((t - least) % 3);
    auto Get = [&](LL times, LL k) -> int {
      char c = 'A';
      while (times > 0) {
        LL half = (1LL << (times - 1));
        if (k > half) {
          k -= half;
          c = mp[c][1];
        } else {
          c = mp[c][0];
        }
        --times;
      }
      return int(c - 'A');
    };
    cout << char('A' + (dd + cd + Get(least, k)) % 3) << '\n';
  }
  return 0;
}

// GOOD LUCK!!!
