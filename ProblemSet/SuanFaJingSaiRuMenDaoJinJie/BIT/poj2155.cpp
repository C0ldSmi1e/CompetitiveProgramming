/**
*  Author: Daniel
*  Created Time: 2020-10-19 09:51:59
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
const int N = 1010, M = 1010;

int T;
int n, m;
int tr[N][N];

#define lowbit(x) x & -x

void add(int x, int y, int c)
{
    for (int i = x; i <= n; i += lowbit(i))
        for (int j = y; j <= n; j += lowbit(j))
            tr[i][j] += c;
}

int sum(int x, int y)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        for (int j = y; j; j -= lowbit(j))
            res += tr[i][j];
    return res;
}

// read the question carefully!!!
int main()
{
    scanf("%d", &T);
    while (T -- )
    {
        scanf("%d%d", &n, &m);

        for (int i = 0; i <= n; i ++ )
            for (int j = 0; j <= n; j ++ )
                tr[i][j] = 0;

        while (m -- )
        {
            char op[2];
            scanf("%s", op);

            if (op[0] == 'C')
            {
                int x1, y1, x2, y2;
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                add(x1, y1, 1);
                add(x2 + 1, y2 + 1, 1);
                add(x1, y2 + 1, -1);
                add(x2 + 1, y1, -1);
            }
            else
            {
                int x, y;
                scanf("%d%d", &x, &y);
                printf("%d\n", sum(x, y) % 2 ? 1 : 0);
            }
        }
        cout << '\n';
    }
    return 0;
}
