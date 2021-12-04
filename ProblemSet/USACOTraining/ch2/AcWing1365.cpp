/**
 * Author: Daniel
 * Created Time: 2020-12-10 12:59:42
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

int n;

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    int s = (n + 1) * n / 2;
    if (s & 1)
    {
        cout << "0\n";
        return 0;
    }

    int m = n / 2;
    map<int, LL> h;
    for (int bit = 0; bit < 1 << m; bit ++ )
    {
        int sum = 0;
        for (int i = 0; i < m; i ++ )
            if ((bit >> i) & 1)
                sum += i + 1;
        h[sum] ++ ;
    }

    LL res = 0;
    m = n - m;
    for (int bit = 0; bit < 1 << m; bit ++ )
    {
        int sum = 0;
        for (int i = 0; i < m; i ++ )
            if ((bit >> i) & 1)
                sum += n / 2 + i + 1;
        res += h[s / 2 - sum];
    }
    cout << res / 2 << '\n';
    return 0;
}

// GOOD LUCK!!!
