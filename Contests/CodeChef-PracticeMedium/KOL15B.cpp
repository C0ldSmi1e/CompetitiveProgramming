
// Problem : Finding Hardest Sum Value
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/KOL15B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define SZ(x) x.size()
#define EB emplace_back
#define MP(x, y) make_pair(x, y)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef multiset<int> MSET;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 1010, M = 1010, INF = 0x3f3f3f3f;

int T;
int n, m;
int a[N][N];
int l[N][N], r[N][N], d[N][N], u[N][N];
int ml[N][N], mr[N][N], md[N][N], mu[N][N];

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n >> m;
		for (int i = 0; i <= n + 1; i ++ )
			for (int j = 0; j <= m + 1; j ++ )
			{
				l[i][j] = r[i][j] = d[i][j] = u[i][j] = 0;
				ml[i][j] = mr[i][j] = md[i][j] = mu[i][j] = INF;
			}
				
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= m; j ++ )
				cin >> a[i][j];
		
		int maxa;
		
		// row left
		for (int i = 1; i <= n; i ++ )
		{
			maxa = 0;
			for (int j = 1; j <= m; j ++ )
			{
				l[i][j] = l[i][j - 1] + a[i][j];
				ml[i][j] = l[i][j] - maxa;
				maxa = max(maxa, l[i][j]);
			}
		}
		
		// row right
		for (int i = 1; i <= n; i ++ )
		{
			maxa = 0;
			for (int j = m; j >= 1; j -- )
			{
				r[i][j] = r[i][j + 1] + a[i][j];
				mr[i][j] = r[i][j] - maxa;
				maxa = max(maxa, r[i][j]);
			}
		}
		
		// col down
		for (int j = 1; j <= m; j ++ )
		{
			maxa = 0;
			for (int i = 1; i <= n; i ++ )
			{
				d[i][j] = d[i - 1][j] + a[i][j];
				md[i][j] = d[i][j] - maxa;
				maxa = max(maxa, d[i][j]);
			}
		}
		
		// col up
		for (int j = 1; j <= m; j ++ )
		{
			maxa = 0;
			for (int i = n; i >= 1; i -- )
			{
				u[i][j] = u[i + 1][j] + a[i][j];
				mu[i][j] = u[i][j] - maxa;
				maxa = max(maxa, u[i][j]);
			}
		}
				
		LL res = INF;
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= m; j ++ )
				res = min(res, (LL)(ml[i][j] + mr[i][j] + md[i][j] + mu[i][j]) - 3LL * a[i][j]);
		cout << res << '\n';
	}
    return 0;
}
