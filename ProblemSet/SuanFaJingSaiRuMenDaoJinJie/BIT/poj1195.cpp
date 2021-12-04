/**
*  Author: Daniel
*  Created Time: 2020-10-19 00:05:36
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
const int N = 1050, M = 1010;

int type;
int n;
int x, y, a;
int l, b, r, t;
LL tr[N][N];

#define lowbit(x) x & -x

void add(int x, int y, int c)
{
    for (int i = x; i < N; i += lowbit(i))
        for (int j = y; j < N; j += lowbit(j))
            tr[i][j] += c;
}

LL sum(int x, int y)
{
    LL res = 0;
    for (int i = x; i; i -= lowbit(i))
        for (int j = y; j; j -= lowbit(j))
            res += tr[i][j];
    return res;
}

LL get(int xa, int ya, int xb, int yb)
{
    return sum(xb, yb) + sum(xa - 1, ya - 1) - sum(xa - 1, yb) - sum(xb, ya - 1);
}

// read the question carefully!!!
int main()
{
    while (scanf("%d", &type) && type != 3)
    {
        if (type == 0) scanf("%d", &n);
        else if (type == 1)
        {
            scanf("%d%d%d", &x, &y, &a);
            x ++ , y ++ ;
            add(x, y, a);
        }
        else if (type == 2)
        {
            scanf("%d%d%d%d", &l, &b, &r, &t);
            printf("%lld\n", get(l + 1, b + 1, r + 1, t + 1));
        }
    }
    return 0;
}

