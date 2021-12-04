/**
 * Author: Daniel
 * Created Time: 2021-04-26 09:21:50
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
const int N = 1050, M = 1010;

int n, m;
int board[N], rail[N], sum[N];
int mid, tot;

bool dfs(int u, int start)
{
    if (!u) return true;
    if (tot < sum[u]) return false;
    if (u + 1 > mid || rail[u] != rail[u + 1]) start = 1;
    for (int i = start; i <= n; i ++ )
    {
        if (i > start && board[i] == board[i - 1]) continue;
        if (board[i] >= rail[u])
        {
            tot -= rail[u];
            board[i] -= rail[u];
            if (board[i] < rail[1]) tot -= board[i];
            bool flag = dfs(u - 1, i);
            if (board[i] < rail[1]) tot += board[i];
            board[i] += rail[u];
            tot += rail[u];
            if (flag) return true;
        }
    }
    return false;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> board[i], tot += board[i];
    cin >> m;
    for (int i = 1; i <= m; i ++ ) cin >> rail[i];
    sort(board + 1, board + 1 + n);
    sort(rail + 1, rail + 1 + m);
    for (int i = 1; i <= m; i ++ ) sum[i] = sum[i - 1] + rail[i];
    int l = 0, r = m;
    while (l < r)
    {
        mid = l + r + 1 >> 1;
        if (dfs(mid, 1)) l = mid;
        else r = mid - 1;
    }
    cout << r << '\n';
    return 0;
}

// GOOD LUCK!!!
