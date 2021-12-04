/**
 * Author: Daniel
 * Created Time: 2020-12-11 23:28:55
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
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 100010, M = 1010;

int T;
int n, m;
int a[N];

int get_pos()
{
    for (int i = n; i >= 1; i -- )
        if (a[i] != i)
            return i;
    return -1;
}

// read the question carefully!!!
int main()
{
    SOS;
    
    cin >> T;
    while (T -- )
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        int pos = get_pos();
        double res = 1.0;
        while (m -- )
        {
            int r;
            double p;
            cin >> r >> p;
            if (r >= pos) res = res * ((double)1.0 - p);
        }
        if (pos == -1) cout << (double)1.0 << '\n';
        else cout << (double)1.0 - res << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
