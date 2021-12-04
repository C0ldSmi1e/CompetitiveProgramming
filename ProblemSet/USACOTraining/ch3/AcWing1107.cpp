/**
 * Author: Daniel
 * Created Time: 2020-12-27 15:37:26
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
const int N = 110, M = 1000010;

int g[N][N];
string q[M];
string start = "12345678", target;
map<string, PA<char, string>> pre;
map<string, int> h;

void myset(string s)
{
    for (int i = 0; i < 4; i ++ ) g[0][i] = s[i] - '0';
    for (int i = 4, j = 3; i < 8; i ++ , j -- ) g[1][j] = s[i] - '0';
}

string get()
{
    string res;
    for (int i = 0; i < 4; i ++ ) res += g[0][i] + '0';
    for (int i = 3; i >= 0; i -- ) res += g[1][i] + '0';
    return res;
}

void opA()
{
    for (int i = 0; i < 4; i ++ ) swap(g[1][i], g[0][i]);
}

void opB()
{
    int a = g[0][3], b = g[1][3];
    for (int i = 2; i >= 0; i -- )
    {
        g[0][i + 1] = g[0][i];
        g[1][i + 1] = g[1][i];
    }
    g[0][0] = a;
    g[1][0] = b;
}

void opC()
{
    int t = g[0][1];
    g[0][1] = g[1][1];
    g[1][1] = g[1][2];
    g[1][2] = g[0][2];
    g[0][2] = t;
}

void print(string s)
{
    cout << h[s] << '\n';
    string res;
    while (s != start)
    {
        res += pre[s].F;
        s = pre[s].S;
    }
    reverse(ALL(res));
    cout << res << '\n';
}

// read the question carefully!!!
int main()
{
    SOS;

    for (int i = 0; i < 4; i ++ ) cin >> g[0][i];
    for (int i = 3; i >= 0; i -- ) cin >> g[1][i];
    target = get();

    if (start == target)
    {
        cout << "0\n";
        return 0;
    }

    int hh = 0, tt = -1;
    q[ ++ tt] = start;
    h[start] = 0;

    while (hh <= tt)
    {
        auto t = q[hh ++ ];

        // A
        myset(t);
        opA();
        string A = get();
        if (!h.count(A))
        {
            h[A] = h[t] + 1;
            pre[A] = MP('A', t);
            q[ ++ tt] = A;

            if (A == target)
            {
                print(A);
                return 0;
            }
        }

        // B
        myset(t);       
        opB();
        string B = get();
        if (!h.count(B))
        {
            h[B] = h[t] + 1;
            pre[B] = MP('B', t);
            q[ ++ tt] = B;

            if (B == target)
            {
                print(B);
                return 0;
            }
        }

        // C
        myset(t);
        opC();
        string C = get();
        if (!h.count(C))
        {
            h[C] = h[t] + 1;
            pre[C] = MP('C', t);
            q[ ++ tt] = C;

            if (C == target)
            {
                print(C);
                return 0;
            }
        }
    }
    return 0;
}

// GOOD LUCK!!!
