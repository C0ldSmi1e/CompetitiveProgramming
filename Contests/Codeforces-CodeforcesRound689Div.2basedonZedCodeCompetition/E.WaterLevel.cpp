/**
 * Author: Daniel
 * Created Time: 2020-12-12 10:41:52
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

LL k, l, r, t, x, y;

int finish(int t)
{
    cout << (t ? "Yes" : "No") << '\n';
    return 0;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> k >> l >> r >> t >> x >> y;

    if (x >= y)
    {
        if (k + y <= r) k += y;
        k -= x, t -- ;
        if (x == y) return finish(k >= l && k <= r);
        else return finish(t <= (k - l) / (x - y));
    }
    else
    {
        VE<bool> st(x, false);
        while (t > 0)
        {
            if (st[k % x]) return finish(1);
            st[k % x] = true;

            LL maxa = (k - l) / x;
            k -= maxa * x;
            t -= maxa;

            if (t <= 0) return finish(1);

            if (k + y <= r) k += y;
            k -= x, t -- ;
            if (k < l || k > r) return finish(0);
        }

        return finish(1);
    }
    return 0;
}

// GOOD LUCK!!!
