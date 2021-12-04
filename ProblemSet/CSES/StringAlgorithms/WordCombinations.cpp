/**
 * Author: Daniel
 * Created Time: 2021-05-28 10:39:09
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
 
mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
 
///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////
 
// check the limitation!!!
const int N = 5010, M = 1000010, mod = 1e9 + 7;
 
VI f;
int son[M][26], idx;
int cnt[M];
 
void insert(string &s)
{
    int p = 0;
    for (auto &u : s)
    {
        int c = u - 'a';
        if (!son[p][c]) son[p][c] = ++ idx;
        p = son[p][c];
    }
    cnt[p] ++ ;
}
 
void get(string &s, int x)
{
    int p = 0;
    for (int i = x - 1; i >= 0; i -- )
    {
        int c = s[i] - 'a';
        if (!son[p][c]) return;
        else p = son[p][c];
        if (cnt[p]) f[x] = (f[x] + (LL)cnt[p] * f[i]) % mod;
    }
}
 
// read the question carefully!!!
int main()
{
    SOS;
 
    string s;
    cin >> s;
    int n = SZ(s);
    int m;
    cin >> m;
    VS g(m);
    for (auto &s : g)
    {
        cin >> s;
        reverse(ALL(s));
        insert(s);
    }
    f = VI(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i ++ ) get(s, i);
    f[n] = (f[n] % mod + mod) % mod;
    cout << f[n] << '\n';
    return 0;
}
 
// GOOD LUCK!!!
