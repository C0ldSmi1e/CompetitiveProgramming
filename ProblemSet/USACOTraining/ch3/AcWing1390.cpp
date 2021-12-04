/**
 * Author: Daniel
 * Created Time: 2020-12-27 22:28:11
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

int n, m, p;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int get(PII a, PII b)
{
    b.F -= a.F, b.S -= a.S;
    a = {0, 0};
    return abs(gcd(b.F, b.S));
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> m >> p;

    int S = p * m;
    int res = S + 2;
    res -= get({0, 0}, {n, m});
    res -= get({0, 0}, {p, 0});
    res -= get({p, 0}, {n, m});
    cout << res / 2 << '\n';
    return 0;
}

// GOOD LUCK!!!
