/**
 * Author: Daniel
 * Created Time: 2021-02-24 16:19:46
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
const int N = 300010, M = 1010;

int n;
int a[N];
int tr[N];

void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

LL sum(int x)
{
    LL res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

LL sum(int l, int r)
{
    return sum(r) - sum(l - 1);
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    LL tot = 0;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        a[i] ++ ;
        tot += sum(a[i], n);
        add(a[i], 1);
    }

    cout << tot << '\n';
    for (int i = 1; i < n; i ++ )
    {
        tot += n - a[i];
        tot -= a[i] - 1;
        cout << tot << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
