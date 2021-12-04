/**
 * Author: Daniel
 * Created Time: 2020-12-02 14:07:30
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

int n, a[N];
int cnt[N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 1; i <= n; i ++ ) 
    {
        cin >> a[i];
        cnt[a[i]] ++ ;
    }

    int res = 0;
    for (int i = 1; i <= cnt[1]; i ++ )
        if (a[i] != 1)
        {
            res ++ ;
            if (a[i] == 2)
            {
                for (int j = cnt[1] + 1; j <= n; j ++ )
                    if (a[j] == 1)
                    {
                        swap(a[i], a[j]);
                        break;
                    }
            }
            else
            {
                for (int j = n; j > cnt[1]; j -- )
                    if (a[j] == 1)
                    {
                        swap(a[i], a[j]);
                        break;
                    }
            }
        }

    for (int i = cnt[1] + 1; i <= cnt[1] + cnt[2]; i ++ ) res += a[i] != 2;

    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
