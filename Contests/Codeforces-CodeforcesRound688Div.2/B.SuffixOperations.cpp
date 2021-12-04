/**
 * Author: Daniel
 * Created Time: 2020-12-04 21:14:14
**/

// time-limit: 1000
#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
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
typedef pair<int, int> PII;

template <typename A> using VE = vector<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;
    
///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 200010, M = 1010;

int T;
int n;
LL a[N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n;
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        if (n == 2)
        {
            cout << "0\n";
            continue;
        }

        LL sum = 0;
        for (int i = 2; i <= n; i ++ )
            sum += abs(a[i] - a[i - 1]);

        LL res = 4e18;
        for (int i = 2; i <= n - 1; i ++ )
            res = min(res, sum - abs(a[i] - a[i - 1]) - abs(a[i] - a[i + 1]) + abs(a[i - 1] - a[i + 1]));
        res = min(res, sum - abs(a[1] - a[2]));
        res = min(res, sum - abs(a[n] - a[n - 1]));
        cout << res << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
