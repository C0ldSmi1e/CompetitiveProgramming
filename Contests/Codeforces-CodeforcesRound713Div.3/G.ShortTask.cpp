/**
 * Author: Daniel
 * Created Time: 2021-04-14 23:23:21
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
const int N = 10000010, M = 1010;

int primes[N], cnt;  // 存放所有质数
int minp[N];  // 保存某个数的大于1的最小质因子
int pcnt[N];  // 质因子的种数
int minp_cnt[N];  // 最小质因子的幂次
int fac_cnt[N];  // 因子个数
int fac_sum[N];  // 因子之和
int exminp[N];  // 除了最小质因子外的因子和
int f[N];
bool st[N];  // 标记是否为质数

void init(int n)
{
    st[1] = true;
    fac_sum[1] = 1;
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i])
        {
            minp[i] = i;
            primes[cnt ++ ] = i;
            fac_cnt[i] = 2;
            fac_sum[i] = i + 1;
            minp_cnt[i] = 1;
            exminp[i] = 1;
        }
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            int t = primes[j] * i;
            st[t] = true;
            minp[t] = primes[j];
            if (i % primes[j] == 0)
            {
                fac_cnt[t] = fac_cnt[i] / (minp_cnt[i] + 1) * (minp_cnt[i] + 2);
                fac_sum[t] = fac_sum[i] * primes[j] + exminp[i];
                exminp[t] = exminp[i];
                minp_cnt[t] = minp_cnt[t] + 1;
                break;
            }
            else
            {
                fac_cnt[t] = fac_cnt[i] * fac_cnt[primes[j]];
                fac_sum[t] = fac_sum[i] * fac_sum[primes[j]];
                exminp[t] = fac_sum[i];
                minp_cnt[t] = 1;
            }
        }
    }
    for (int i = 2; i <= n; i ++ )
    {
        int j = i / minp[i];
        pcnt[i] = pcnt[j] + (int)(minp[i] != minp[j]);
    }
}

// read the question carefully!!!
int main()
{
    SOS;

    init(N - 1);
    memset(f, -1, sizeof f);
    for (int i = N - 1; i; i -- ) 
        if (fac_sum[i] < N)
            f[fac_sum[i]] = i;
    int T;
    cin >> T;
    while (T -- )
    {
        int n;
        cin >> n;
        cout << f[n] << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
