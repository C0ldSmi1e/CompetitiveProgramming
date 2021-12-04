/**
 * Author: Daniel
 * Created Time: 2020-12-10 22:53:03
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
typedef unsigned long long ULL;

template <typename A> using VE = vector<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;
    
///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 200010, M = 1010, P = 13331;

bool f[N];
string s;
set<ULL> S;

// read the question carefully!!!
int main()
{
    SOS;

    while (cin >> s, s != ".")
    {
        ULL t = 0;
        for (int i = SZ(s) - 1; i >= 0; i -- )
            t = t * 10 + (s[i] - '0');
        S.IS(t);
    }

    s.clear();
    string k;
    while (cin >> k) s += k;

    int n = SZ(s), res = 0;
    f[0] = true;
    for (int i = 1; i <= n; i ++ )
    {
        ULL t = 0;
        for (int j = i; j >= max(1, i - 9); j -- )
        {
            t = t * 10 + (s[j - 1] - '0');
            if (f[j - 1] && S.count(t))
            {
                f[i] = true;
                break;
            }
        }
        if (f[i]) res = i;
    }
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
