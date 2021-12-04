/**
 * Author: Daniel
 * Created Time: 2020-12-26 14:52:37
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
const int N = 100010, M = 1010;

int n;

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;

    int res = 1, cnt2 = 0, cnt5 = 0;
    for (int i = 1; i <= n; i ++ )
    {
        int x = i;
        while (x % 2 == 0) x /= 2, cnt2 ++ ;
        while (x % 5 == 0) x /= 5, cnt5 ++ ;
        res = res * x % 10;
    }

    for (int i = 0; i < cnt2 - cnt5; i ++ ) res = res * 2 % 10;
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
