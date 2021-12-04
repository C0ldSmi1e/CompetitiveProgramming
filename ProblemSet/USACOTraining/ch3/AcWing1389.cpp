/**
 * Author: Daniel
 * Created Time: 2020-12-27 19:48:39
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

string in, pre, post;
map<char, int> h;

void dfs(int pl, int pr, int il, int ir)
{
    if (pl > pr) return;
    int root = h[pre[pl]];
    dfs(pl + 1, pl + 1 + root - 1 - il, il, root - 1);
    dfs(pl + 1 + root - 1 - il + 1, pr, root + 1, ir);
    post += in[root];
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> in >> pre;
    for (int i = 0; i < SZ(in); i ++ ) h[in[i]] = i;
    
    dfs(0, SZ(pre) - 1, 0, SZ(in) - 1);
    cout << post << '\n';
    return 0;
}

// GOOD LUCK!!!
