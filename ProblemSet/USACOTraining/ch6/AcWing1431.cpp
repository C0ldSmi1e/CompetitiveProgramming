/**
 * Author: Daniel
 * Created Time: 2021-02-01 09:50:04
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
#define SOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10)

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
const int N = 100010, M = 1010;

int state[9];
VI path, ans;
int s[] = {4, 3, 4, 3, 5, 3, 4, 3, 4};
int op[9][10] = 
{
    {0, 1, 3, 4},
    {0, 1, 2},
    {1, 2, 4, 5},
    {0, 3, 6},
    {1, 3, 4, 5, 7},
    {2, 5, 8},
    {3, 4, 6, 7},
    {6, 7, 8},
    {4, 5, 7, 8}
};

bool check()
{
    for (int i = 0; i < 9; i ++ )
        if (state[i] != 0)
            return false;
    return true;
}

void op1(int u)
{
    for (int i = 0; i < s[u]; i ++ )
        state[op[u][i]] = (state[op[u][i]] + 3) % 12;
}

void op2(int u)
{
    for (int i = 0; i < s[u]; i ++ )
        state[op[u][i]] = ((state[op[u][i]] - 3) % 12 + 12) % 12;
}

void dfs(int u)
{
    if (check())
    {
        if (!SZ(ans) || SZ(path) < SZ(ans) || path < ans) ans = path;
        return;
    }
    if (u >= 10) return;

    for (int i = 0; i < 4; i ++ )
    {
        for (int j = 0; j < i; j ++ ) 
        {
            op1(u);
            path.EB(u);
        }
        dfs(u + 1);
        for (int j = 0; j < i; j ++ )
        {
            op2(u);
            path.PB();
        }
    }
}

// read the question carefully!!!
int main()
{
    SOS;

    for (int i = 0; i < 9; i ++ )
    {
        cin >> state[i];
        state[i] %= 12;
    }
    dfs(0);
    for (auto &u : ans) cout << u + 1 << ' ';
    cout << '\n';
    return 0;
}

// GOOD LUCK!!!
