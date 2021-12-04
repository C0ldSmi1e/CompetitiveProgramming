
// Problem : Online Shopping
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/COUPON
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB push_back
#define SZ(x) x.size()
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

const int N = 100010, M = 1010;
const LL INF = 1e18;

int T;
int n, m;
vector<vector<LL>> p, d, f;

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n >> m;
		
		p = vector<vector<LL>> (n + 10, vector<LL>(m + 10, 0LL));
		d = vector<vector<LL>> (n + 10, vector<LL>(m + 10, 0LL));
		f = vector<vector<LL>> (n + 10, vector<LL>(m + 10, INF));
		
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= m; j ++ )
				cin >> p[i][j];
		
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= m; j ++ )
				cin >> d[i][j];
		
		LL prev1 = INF, prev2 = INF;
		for (int i = 1; i <= m; i ++ )
		{
			f[1][i] = p[1][i];
			prev1 = min(prev1, f[1][i]);
		}
		
		for (int i = 2; i <= n; i ++ )
		{
			prev2 = INF;
			for (int j = 1; j <= m; j ++ )
			{
				f[i][j] = f[i - 1][j] + max(0LL, p[i][j] - d[i - 1][j]);
				f[i][j] = min(f[i][j], prev1 + p[i][j]);
				prev2 = min(prev2, f[i][j]);
			}
			prev1 = prev2;
		}
				
		LL res = INF;
		for (int i = 1; i <= m; i ++ ) res = min(res, f[n][i]);
		cout << res << '\n';		
	}
    return 0;
}
