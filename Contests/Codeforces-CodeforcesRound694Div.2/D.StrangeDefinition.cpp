/**
 * Author: Daniel
 * Created Time: 2021-02-18 11:02:37
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

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 300010, M = 1010;

int T;
int n, m;
int a[N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n;
        map<int, int> mp;
        for (int i = 1; i <= n; i ++ ) 
        {
            cin >> a[i];
            int x = a[i];
            for (int j = 2; j <= x / j; j ++ )
                if (x % j == 0)
                    while (x % (j * j) == 0)
                        x /= (j * j);
            mp[x] ++ ;
        }

        int res1 = 0;
        for (auto [x, y] : mp) res1 = max(res1, y);

        map<int, int> mp2;
        for (auto [x, y] : mp)
            if (y % 2 == 0) mp2[1] += y;
            else mp2[x] += y;
        int res2 = 0;
        for (auto [x, y] : mp2) res2 = max(res2, y);

        cin >> m;
        while (m -- )
        {
            LL w;
            cin >> w;
            if (!w) cout << res1 << '\n';
            else cout << max(res1, res2) << '\n';
        }
    }
    return 0;
}

// GOOD LUCK!!!
