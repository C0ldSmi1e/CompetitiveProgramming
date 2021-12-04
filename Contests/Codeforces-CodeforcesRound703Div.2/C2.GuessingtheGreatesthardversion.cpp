/**
 * Author: Daniel
 * Created Time: 2021-02-19 11:33:33
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
const int N = 100010, M = 1010;

int n;
int l, r;

int ask(int l, int r)
{
    cout << "? " << l << ' ' << r << endl;
    cin >> r;
    return r;
}

void answer(int x)
{
    cout << "! " << x << endl;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    int l = 1, r = n;
    int smax = ask(l, r);
    if (l < smax && ask(l, smax) == smax)
    {
        r = smax - 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (ask(mid, smax) == smax) l = mid;
            else r = mid - 1;
        }
    }
    else
    {
        l = smax + 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (ask(smax, mid) == smax) r = mid;
            else l = mid + 1;
        }
    }
    answer(r);
    return 0;
}

// GOOD LUCK!!!
