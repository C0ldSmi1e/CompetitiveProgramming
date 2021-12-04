/**
* Author: Daniel
* Created Time: 2020-11-24 22:39:23
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
        VE<int> a(n), cnt(n + 1);
        for (auto &u : a)
        {
            cin >> u;
            cnt[u] ++ ;
        }

        int res = -1;
        for (int i = n; i; i -- )
            if (cnt[i] == 1)
                res = i;
        
        if (res == -1) cout << "-1\n";
        else
        {
            for (int i = 0; i < n; i ++ )
                if (a[i] == res)
                {
                    cout << i + 1 << '\n';
                    break;
                }
        }
    }
    return 0;
}

// GOOD LUCK!!!
