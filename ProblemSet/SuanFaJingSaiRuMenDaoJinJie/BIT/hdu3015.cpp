/**
*  Author: Daniel
*  Created Time: 2020-10-19 19:46:09
**/

#include <bits/stdc++.h>

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
const int N = 100010, M = 1010;

int n;
int order[N];
LL cnt[N], s[N];
PII a[N];

bool cmp(PII a, PII b)
{
    return a.S > b.S;
}

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

LL sum(LL tr[], int l, int r)
{
    return sum(tr, r) - sum(tr, l - 1);
}

// read the question carefully!!!
int main()
{
    while (~scanf("%d", &n)) 
    {
        memset(cnt, 0, sizeof cnt);
        memset(s, 0, sizeof s);

        for (int i = 1; i <= n; i ++ ) scanf("%d%d", &a[i].F, &a[i].S);

        sort(a + 1, a + 1 + n);

        order[1] = 1;
        for (int i = 2; i <= n; i ++ )
            if (a[i].F != a[i - 1].F) order[i] = i;
            else order[i] = order[i - 1];

        for (int i = 1; i <= n; i ++ ) a[i].F = order[i];

        sort(a + 1, a + 1 + n, cmp);

        order[n] = 1;
        for (int i = n - 1; i; i -- )                            
            if (a[i].S != a[i + 1].S) order[i] = n - i + 1;
            else order[i] = order[i + 1];

        LL res = 0;
        for (int i = 1; i <= n; i ++ )
        {
            res += (LL)order[i] * ((LL)a[i].F * sum(cnt, 1, a[i].F - 1) - sum(s, 1, a[i].F - 1));
            res += (LL)order[i] * (sum(s, a[i].F, N - 1) - (LL)a[i].F * sum(cnt, a[i].F, N - 1));
            add(cnt, a[i].F, 1);
            add(s, a[i].F, a[i].F);
        }
        printf("%lld\n", res);
    }
    return 0;
}
