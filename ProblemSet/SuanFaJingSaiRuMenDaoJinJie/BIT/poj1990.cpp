/**
*  Author: Daniel
*  Created Time: 2020-10-19 13:06:16
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
const int N = 200010, M = 1010;

int n;
PII a[N];
LL Tr1[N], tr2[N];

#define lowbit(x) x & -x

void add(LL tr[], int x, int c)
{
    for (int i = x; i < N; i += lowbit(i)) tr[i] += c;
}

LL sum(LL tr[], int x)
{
    LL res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

// read the question carefully!!!
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d%d", &a[i].F, &a[i].S);
    sort(a + 1, a + 1 + n);

    LL res = 0;
    for (int i = 1; i <= n; i ++ )
    {
        res += (LL)a[i].F * (sum(Tr1, a[i].S - 1) * a[i].S - sum(tr2, a[i].S));
        res += (LL)a[i].F * ((sum(tr2, N - 1) - sum(tr2, a[i].S)) - a[i].S * (sum(Tr1, N - 1) - sum(Tr1, a[i].S)));
        add(Tr1, a[i].S, 1);
        add(tr2, a[i].S, a[i].S);
    }
    printf("%lld\n", res);
    return 0;
}
