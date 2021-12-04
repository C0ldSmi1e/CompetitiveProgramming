/**
*  Author: Daniel
*  Created Time: 2020-10-19 12:51:27
**/

#include <queue>    
#include <vector>   
#include <cstdio>   
#include <cstdlib>  
#include <cstring>  
#include <iomanip>  
#include <iostream> 
#include <algorithm>

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define EB emplace_back
#define SZ(x) (int)x.size()
#define MP(x, y) make_pair(x, y)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

// check the limitation!!!
const int N = 100010, M = N * 2;

int n, m;
int h[N], e[M], ne[M], idx;
int l[N], r[N];
int f[N];
int tr[N];

void add_edge(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int now = 1;
void dfs(int u)
{
    l[u] = now;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (l[j]) continue;

        now ++ ;
        dfs(j);
    }
    r[u] = now;
}

#define lowbit(x) x & -x

void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

// read the question carefully!!!
int main()
{
    memset(h, -1, sizeof h);

    scanf("%d", &n);
    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add_edge(a, b);
        add_edge(b, a);
    }

    dfs(1);

    for (int i = 1; i <= n; i ++ ) 
    {
        add(i, 1);
        f[i] = 1;
    }

    scanf("%d", &m);
    while (m -- )
    {
        int x;
        char op[2];
        scanf("%s%d", op, &x);
        
        if (op[0] == 'Q') printf("%d\n", sum(r[x]) - sum(l[x] - 1));
        else 
        {
            add(l[x], (f[x] ^ 1) - f[x]);
            f[x] ^= 1;
        }
    }
    return 0;
}

