/**
 * Author: Daniel
 * Created Time: 2021-01-18 11:06:45
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
const int N = 100010, M = 1010, INF = 0x3f3f3f3f;

int get(string a, string b)
{
    int res = 0;
    for (int i = 0; i < SZ(a); i ++ )
        if (a[i] != b[i])
        {
            a[i] ^= 1;
            a[i + 1] ^= 1;
            res ++ ;
        }
    return a.back() == b.back() ? res : INF;
}

// read the question carefully!!!
int main()
{
    SOS;

    string a, b;
    cin >> a >> b;
    for (auto &c : a) c = c == '*' ? '0' : '1';
    for (auto &c : b) c = c == '*' ? '0' : '1';
    int res = get(a, b);
    reverse(ALL(a));
    reverse(ALL(b));
    res = min(res, get(a, b));
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
