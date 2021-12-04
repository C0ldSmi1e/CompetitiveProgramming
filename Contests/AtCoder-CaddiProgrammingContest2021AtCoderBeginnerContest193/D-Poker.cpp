/**
 * Author: Daniel
 * Created Time: 2021-02-27 20:29:14
**/

// time-limit: 2000
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
const int N = 1000010, M = 1010;

int k;
LL cnt[10];
string s, t;

int qp(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> k >> s >> t;
    for (int i = 1; i <= 9; i ++ ) cnt[i] = k;
    for (auto &c : s) 
        if (c != '#')
            cnt[c - '0'] -- ;
    for (auto &c : t) 
        if (c != '#')
            cnt[c - '0'] -- ;
    LL tot = 0;
    for (int i = 1; i <= 9; i ++ ) tot += cnt[i];
    LL up = 0;
    LL down = tot * (tot - 1);
    for (int i = 1; i <= 9; i ++ )
        for (int j = 1; j <= 9; j ++ )
        {
            if (!cnt[i] || !cnt[j]) continue;
            if (i == j && cnt[i] == 1) continue;
            LL s1 = 0, s2 = 0;
            VL cnt1(10), cnt2(10);
            for (auto &c : s)
                if (c != '#')
                    cnt1[c - '0'] ++ ;
            cnt1[i] ++ ;
            for (auto &c : t)
                if (c != '#')
                    cnt2[c - '0'] ++ ;
            cnt2[j] ++ ;
            for (int k = 1; k <= 9; k ++ )
            {
                s1 += k * qp(10, cnt1[k]);
                s2 += k * qp(10, cnt2[k]);
            }
            if (s1 > s2)
            {
                if (i != j) up += cnt[i] * cnt[j];
                else up += cnt[i] * (cnt[i] - 1);
            }
        }
    cout << (double)up / down << '\n';
    return 0;
}

// GOOD LUCK!!!
