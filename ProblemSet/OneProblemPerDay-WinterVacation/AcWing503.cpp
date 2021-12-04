/**
 * Author: Daniel
 * Created Time: 2021-02-06 18:20:58
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
int r[N], d[N];
int s[N], t[N];
LL temp[N];

bool check(int x)
{
    for (int i = 0; i <= n + 1; i ++ ) temp[i] = 0;
    for (int i = 1; i <= x; i ++ )
    {
        temp[s[i]] += d[i];
        temp[t[i] + 1] -= d[i];
    }
    for (int i = 1; i <= n; i ++ )
    {
        temp[i] += temp[i - 1];
        if (temp[i] > r[i]) return false;
    }
    return true;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> r[i];
    for (int i = 1; i <= m; i ++ ) cin >> d[i] >> s[i] >> t[i];

    int l = 1, r = m;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (!check(mid)) r = mid;
        else l = mid + 1;
    }

    if (!check(r)) cout << "-1\n" << r << '\n';
    else cout << "0\n";
    return 0;
}

// GOOD LUCK!!!
