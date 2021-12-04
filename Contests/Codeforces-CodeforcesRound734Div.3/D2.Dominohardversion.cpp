/**
 * Author: Daniel
 * Created Time: 2021-09-20 20:04:23
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
const int N = 100010, M = 1010;



// read the question carefully!!!
int main()
{
    SOS;

    int T;
    cin >> T;
    while (T -- )
    {
        int n, m, k;
        cin >> n >> m >> k;
        VS g(n, string(m, '#'));
        auto get = [&](int x1, int y1, int x2, int y2) -> char
        {
            set<char> S;
            int dx[4] = {-1, 1, 0, 0};
            int dy[4] = {0, 0, -1, 1};
            for (int i = 0; i < 4; i ++ )
            {
                int tx = x1 + dx[i];
                int ty = y1 + dy[i];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
                if (g[tx][ty] != '#') S.IS(g[tx][ty]);
            }
            for (int i = 0; i < 4; i ++ )
            {
                int tx = x2 + dx[i];
                int ty = y2 + dy[i];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
                if (g[tx][ty] != '#') S.IS(g[tx][ty]);
            }
            for (char c = 'a'; c <= 'z'; c ++ )
                if (S.count(c) == 0)
                    return c;
            assert(false);
            return 'a';
        };
        auto draw = [&](int x, int y) -> void
        {
            for (int i = 0; i < n; i ++ )
                for (int j = 0; j < m; j ++ )
                    if (g[i][j] == '#')
                    {
                        assert(i + 1 < n && g[i + 1][j] == '#');
                        assert(j + 1 < m && g[i][j + 1] == '#');
                        assert(i + 1 < n && j + 1 < m && g[i + 1][j + 1] == '#');
                        if (x > 0)
                        {
                            x -= 2;
                            g[i][j] = g[i][j + 1] = get(i, j, i, j + 1);
                            g[i + 1][j] = g[i + 1][j + 1] = get(i + 1, j, i + 1, j + 1);
                        }
                        else
                        {
                            y -= 2;
                            g[i][j] = g[i + 1][j] = get(i, j, i + 1, j);
                            g[i][j + 1] = g[i + 1][j + 1] = get(i, j + 1, i + 1, j + 1);
                        }
                    }
            assert(x == 0 && y == 0);
        };
        if (n % 2 == 0 && m % 2 == 0)
        {
            if (k & 1)
            {
                cout << "NO\n";
                continue;
            }
            else draw(k, n * m / 2 - k);
        }
        else if (m % 2 == 0)
        {
            int need = m / 2;
            if (k < need || (k - need) % 2 == 1)
            {
                cout << "NO\n";
                continue;
            }
            else
            {
                int kk = n * m / 2 - k;
                for (int j = 0, c = 0; j < m; j += 2)
                {
                    g[0][j] = g[0][j + 1] = (char) (c + 'a');
                    k -- ;
                    c = (c + 1) % 26;
                }
                draw(k, kk);
            }
        }
        else if (n % 2 == 0)
        {
            int left = n * m / 2 - k;
            int need = n / 2;
            if (left < need || (left - need) % 2 == 1)
            {
                cout << "NO\n";
                continue;
            }
            else
            {
                int kk = n * m / 2 - k;
                for (int i = 0, c = 0; i < n; i += 2)
                {
                    g[i][0] = g[i + 1][0] = (char) (c + 'a');
                    kk -- ;
                    c = (c + 1) % 26;
                }
                draw(k, kk);
            }
        }
        else assert(false);
        cout << "YES\n";
        for (auto &s : g)
            cout << s << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
