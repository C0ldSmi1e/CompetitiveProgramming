/**
*  Author: Daniel
*  Created Time: 2020-10-19 22:15:15
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
int tr[N];

#define lowbit(x) x & -x

void add(int x, int c)
{
    for (int i = x; i < N; i += lowbit(i)) tr[i] += c;
}

int query(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int query(int l, int r)
{
    return query(r) - query(l - 1);
}

// read the question carefully!!!
int main()
{
    while (~scanf("%d", &n))
    {
        memset(tr, 0, sizeof tr);
        while (n -- )
        {
            int t;
            scanf("%d", &t);

            if (t == 0)
            {
                int x;
                scanf("%d", &x);
                add(x, 1);
            }
            else if (t == 1)
            {
                int x;
                scanf("%d", &x);
                int s = query(x, x);
                if (!s) puts("No Elment!");
                else add(x, -1);
            }
            else if (t == 2)
            {
                int a, k;
                scanf("%d%d", &a, &k);
                int tot = query(a + 1, N - 1);
                if (tot < k) puts("Not Find!");
                else
                {
                    int l = a + 1, r = N - 1;
                    while (l < r)
                    {
                        int mid = l + r >> 1;
                        if (query(a + 1, mid) >= k) r = mid;
                        else l = mid + 1;
                    }
                    printf("%d\n", r);
                }
            }
        }
    }
    return 0;
}

