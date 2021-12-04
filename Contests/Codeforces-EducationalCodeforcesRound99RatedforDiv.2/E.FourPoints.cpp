/**
 * Author: Daniel
 * Created Time: 2020-12-04 10:43:44
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
const int N = 4, M = 1010;

int T;
PII a[N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        VE<int> side;
        for (int i = 0; i < N; i ++ ) 
        {
            cin >> a[i].F >> a[i].S;
            for (int j = 0; j < i; j ++ )
            {
                side.EB(abs(a[i].F - a[j].F));
                side.EB(abs(a[i].S - a[j].S));
            }
        }

        assert(SZ(side) == 12);
        sort(a, a + N);

        LL res = 4e18;
        do
        {
            for (auto &len : side)
            {
                LL sum = 0;
                VE<int> tx, ty;
                for (int i = 0; i < N; i ++ )
                {
                    tx.EB(a[i].F);
                    ty.EB(a[i].S);
                }
                tx[1] -= len, tx[2] -= len, ty[2] -= len, ty[3] -= len;
                sort(ALL(tx));
                sort(ALL(ty));
                for (int i = 0; i < N; i ++ )
                {
                    sum += abs(tx[i] - tx[1]);
                    sum += abs(ty[i] - ty[1]);
                }
                res = min(res, sum);
            }
        } while (next_permutation(a, a + N));
        cout << res << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
