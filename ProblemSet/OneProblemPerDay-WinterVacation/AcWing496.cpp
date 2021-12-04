/**
 * Author: Daniel
 * Created Time: 2021-02-12 01:23:38
**/

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
const int N = 1000010, M = 1010;

int n, m;
int a[N];
int q[N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> m >> n;
    int hh = 0, tt = -1, res = 0;
    for (int i = 0; i < n; i ++ )
    {
        int x;
        cin >> x;
        bool flag = false;
        for (int j = hh; j <= tt; j ++ )
            if (q[j] == x)
                flag = true;
        if (!flag)
        {
            res ++ ;
            if (tt - hh + 1 == m) hh ++ ;
            q[ ++ tt] = x;
        }
    }
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
