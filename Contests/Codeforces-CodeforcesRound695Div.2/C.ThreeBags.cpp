/**
 * Author: Daniel
 * Created Time: 2021-01-28 11:27:09
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
const int N = 300010, M = 1010;

int n[3];
int a[3][N];
LL sum[3];

// read the question carefully!!!
int main()
{
    SOS;

    for (int i = 0; i < 3; i ++ ) cin >> n[i];

    LL tot = 0;
    for (int i = 0; i < 3; i ++ )
    {
        for (int j = 0; j < n[i]; j ++ ) 
        {
            cin >> a[i][j];
            sum[i] += a[i][j];
        }
        tot += sum[i];
        sort(a[i], a[i] + n[i]);
    }

    LL res = 0;
    for (int i = 0; i < 3; i ++ )
        for (int j = i + 1; j < 3; j ++ )
            res = max(res, tot - 2LL * (a[i][0] + a[j][0]));

    for (int i = 0; i < 3; i ++ )
        res = max(res, tot - 2LL * sum[i]);

    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
