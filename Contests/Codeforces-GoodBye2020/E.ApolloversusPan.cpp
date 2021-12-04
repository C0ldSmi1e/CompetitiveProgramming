/**
 * Author: Daniel
 * Created Time: 2020-12-31 18:46:09
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

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 500010, M = 60, mod = 1e9 + 7;

int T;
int n;
LL x[N];
int cnt[M];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        memset(cnt, 0, sizeof cnt);

        cin >> n;
        for (int i = 0; i < n; i ++ )
        {
            cin >> x[i];
            for (int bit = 0; bit < M; bit ++ )
                cnt[bit] += ((x[i] >> bit) & 1LL); 
        }

        int res = 0;
        for (int i = 0; i < n; i ++ )
        {
            int and_sum = 0, or_sum = 0;
            for (int bit = 0; bit < M; bit ++ )
            {
                int t = (x[i] >> bit) & 1LL;
                and_sum = (and_sum + t * (cnt[bit] * ((1LL << bit) % mod)) % mod) % mod;

                if ((x[i] >> bit) & 1LL) or_sum = (or_sum + (1LL << bit) % mod * n % mod) % mod;
                else or_sum = (or_sum + (1LL << bit) % mod * cnt[bit] % mod) % mod;
            }
            res = (res + (LL)and_sum * or_sum % mod) % mod;
        }
        cout << res << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
