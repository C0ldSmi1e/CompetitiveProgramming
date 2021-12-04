/**
* Author: Daniel
* Created Time: 2020-11-24 23:52:00
**/

// time-limit: 2000
#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define EB emplace_back
#define lowbit(x) (x & -x)
#define SZ(x) (int)(x.size())
#define MP(x, y) make_pair(x, y)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define SOS; ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

typedef long long LL;
typedef pair<int, int> PII;

template <typename A> using VE = vector<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;
    
///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 200010, M = 2 * N;

int T;
int n;
int h[N], e[M], ne[M], idx;
int q[M], d[N], cnt[N];

void add_edge(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n;
        for (int i = 1; i <= n; i ++ ) 
        {
            h[i] = -1;
            cnt[i] = 1;
            d[i] = 0;
        }

        for (int i = 0; i < n; i ++ )
        {
            int a, b;
            cin >> a >> b;
            add_edge(a, b);
            add_edge(b, a);
            d[a] += 2, d[b] += 2;
        }

        int hh = 0, tt = -1;
        for (int i = 1; i <= n; i ++ )
            if (d[i] == 2)
                q[ ++ tt] = i;

        while (hh <= tt)
        {
            int t = q[hh ++ ];

            for (int i = h[t]; ~i; i = ne[i])
            {
                int j = e[i];

                d[j] -= 2;
                cnt[j] += cnt[t];
                if (d[j] == 2) q[ ++ tt] = j;
            }
        }

        LL res = 0;
        for (int i = 1; i <= n; i ++ )
            if (d[i] == 4)
            {
                res += (LL)cnt[i] * (cnt[i] - 1) / 2LL;
                res += (LL)cnt[i] * (n - cnt[i]);
            }
        cout << res << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
