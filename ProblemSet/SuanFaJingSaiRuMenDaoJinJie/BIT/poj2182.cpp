/**
*  Author: Daniel
*  Created Time: 2020-10-18 21:16:34
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
const int N = 100010, M = 1010;

int n;
int a[N];
int tr[N], res[N];

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
    IOS

    cin >> n;
    for (int i = 2; i <= n; i ++ ) cin >> a[i];
    for (int i = 1; i <= n; i ++ ) add(i, 1);

    for (int i = n; i; i -- )
    {
        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (sum(mid) >= a[i] + 1) r = mid;
            else l = mid + 1;
        }
        add(r, -1);
        res[i] = r;
    }

    for (int i = 1; i <= n; i ++ ) cout << res[i] << '\n';
    return 0;
}
