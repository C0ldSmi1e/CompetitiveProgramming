/**
 * Author: Daniel
 * Created Time: 2021-03-11 23:32:05
**/

// time-limit: 1000
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
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;
typedef unsigned long long ULL;
typedef pair<double, double> PDD;
typedef vector<pair<int, int> > VPII;

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
const int N = 100010, M = 1010;

int T;
int n;

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n;
        VL miner, dia;
        int j = 0, k = 0;
        for (int i = 0; i < 2 * n; i ++ )
        {
            LL x, y;
            cin >> x >> y;
            if (!x) dia.EB(abs(y));
            else miner.EB(abs(x));
        }
        sort(ALL(miner));
        sort(ALL(dia));
        double res = 0;
        for (int i = 0; i < n; i ++ ) 
            res += sqrt(dia[i] * dia[i] + miner[i] * miner[i]);
        cout << res << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
