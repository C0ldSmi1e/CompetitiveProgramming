/**
*  Author: Daniel
*  Created Time: 2020-10-20 18:25:57
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
const int N = 1000010, M = 1010;

int T;
int n, p, k;
int tr[N], mod[N];
LL w[N];

#define lowbit(x) (x & -x)

void update(int x)
{
    for (int i = x; i <= n; i += lowbit(i))
	{
		tr[i] = mod[i];
        int len = lowbit(i);
		for (int j = 1; j < len; j <<= 1)
			tr[i] = max(tr[i], tr[i - j]);
	}
}

int query(int l, int r)
{
    int res = 0x3f3f3f3f;
    while (true)
    {
        res = min(res, mod[r]);
        if (l == r) break;
        for (r -- ; r - lowbit(r) >= l; r -= lowbit(r))
            res = min(res, tr[r]);
    }
    return res;
}

// read the question carefully!!!
int main()
{
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc ++ )
    {
        memset(tr, 0x3f, sizeof tr);
        memset(mod, 0x3f, sizeof mod);

        scanf("%d%d%d", &n, &p, &k);

        mod[w[0] % p + 1] = 0;
        for (int i = 1; i <= n; i ++ )
        {
            scanf("%lld", &w[i]);
            w[i] += w[i - 1];
        }

        LL res = -1;
        for (int i = 1; i <= n; i ++ )
        {
            int x = w[i] % p;

            // x >= y
            int y = max(0, x - k);
            int idx = query(y + 1, x + 1);
            if (idx < i) res = max(res, (w[i] - w[idx]) / p);

            // x < y
            y = min(p, x + p - k);
            idx = query(y + 1, p + 1);
            if (idx < i) res = max(res, (w[i] - w[idx]) / p);

            mod[w[i] % p + 1] = min(mod[w[i] % p + 1], i);
            update(w[i] % p + 1);
        }
        printf("Case %d: %lld\n", tc, res);
    }
    return 0;
}

