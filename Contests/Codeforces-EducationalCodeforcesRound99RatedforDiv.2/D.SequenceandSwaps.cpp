/**
 * Author: Daniel
 * Created Time: 2020-12-04 10:27:28
**/

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
const int N = 100010, M = 1010;

int T;
int n, x;
int a[N];

bool check()
{
    for (int i = 2; i <= n; i ++ )
        if (a[i] < a[i - 1])
            return false;
    return true;
}

int find(int st)
{
    for (int i = st; i <= n; i ++ )
        if (a[i] > x)
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
        cin >> n >> x;
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        int cur = 1, res = 0;
        while (!check())
        {
            int t = find(cur);
            if (t == -1) break;

            swap(x, a[t]);
            cur = t + 1;
            res ++ ;
        }

        if (check()) cout << res << '\n';
        else cout << "-1\n";
    }
    return 0;
}

// GOOD LUCK!!!
