/**
 * Author: Daniel
 * Created Time: 2021-03-31 00:22:26
**/

// time-limit: 3500
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
typedef pair<LL, LL> PLL;
typedef vector<string> VS;
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

int n;
int din[N], d[N];
bool st[N];

bool ask(int x, int y)
{
    cout << "? " << x << ' ' << y << endl;
    string res;
    cin >> res;
    return res == "Yes";
}

void answer(int x, int y)
{
    cout << "! " << x << ' ' << y << endl;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> din[i], d[i] = din[i];
    while (true)
    {
        bool flag = false;
        for (int i = 1; i <= n; i ++ )
            if (!st[i] && !d[i])
            {
                flag = true;
                st[i] = true;
                for (int j = 1; j <= n; j ++ ) d[j] -- ;
                break;
            }
        if (!flag) break;
    }
    VE<PA<int, PII>> a;
    for (int i = 1; i <= n; i ++ )
        for (int j = i + 1; j <= n; j ++ )
            if (!st[i] && !st[j])
                a.EB(MP(abs(din[i] - din[j]), MP(i, j)));
    sort(RALL(a));
    for (int i = 0; i < SZ(a); i ++ )
    {
        int x = a[i].S.F, y = a[i].S.S;
        if (d[x] > d[y]) swap(x, y);
        if (ask(y, x))
        {
            answer(x, y);
            return 0;
        }
    }
    answer(0, 0);
    return 0;
}

// GOOD LUCK!!!
