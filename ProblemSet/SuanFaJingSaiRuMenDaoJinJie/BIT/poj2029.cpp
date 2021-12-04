/**
*  Author: Daniel
*  Created Time: 2020-10-19 09:35:11
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
const int N = 110, M = 1010;

int n;
int w, h;
int s, t;
int sum[N][N];

// read the question carefully!!!
int main()
{
    while (scanf("%d", &n), n)
    {
        memset(sum, 0, sizeof sum);

        scanf("%d%d", &w, &h);
        while (n -- )
        {
            int x, y;
            scanf("%d%d", &x, &y);
            sum[x][y] ++ ;
        }

        scanf("%d%d", &s, &t);

        int res = 0;
        for (int i = 1; i <= w; i ++ )
            for (int j = 1; j <= h; j ++ )
            {
                sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
                if (i >= s && j >= t) 
                    res = max(res, sum[i][j] + sum[i - s][j - t] - sum[i - s][j] - sum[i][j - t]);
            }
        printf("%d\n", res);
    }
    return 0;
}
