/**
 * Author: Daniel
 * Created Time: 2021-05-18 21:02:51
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
const int N = 100010, M = 1010;

string s;
set<int> S1, S2;
set<string> res;
string t;

void dfs(int u)
{
    if (u >= 4)
    {
        int cnt = 0;
        for (auto &u : S1)
            for (int i = 0; i < 4; i ++ )
                if (u == t[i] - '0')
                {
                    cnt ++ ;
                    break;
                }
        if (cnt == SZ(S1)) res.IS(t);
        return;
    }
    for (int i = 0; i < 10; i ++ )
        if (S1.count(i) || S2.count(i))
        {
            t += (char)('0' + i);
            dfs(u + 1);
            t.PB();
        }
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> s;
    for (int i = 0; i < 10; i ++ )
        if (s[i] == 'o') S1.IS(i);
        else if (s[i] == '?') S2.IS(i);
    dfs(0);
    cout << SZ(res) << '\n';
    int cnt = 0;
//    for (auto &u : res)
//    {
//        cout << u;
//        cnt ++ ;
//        if (cnt % 10 == 0) cout << '\n';
//        else cout << ' ';
//    }
    return 0;
}

// GOOD LUCK!!!
