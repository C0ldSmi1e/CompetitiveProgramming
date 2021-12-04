
// Problem : Little Elephant and Painting
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/LEPAINT
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

const int N = 55, M = 110;
const double eps = 1e-12;

int T;
int n, c, k;
double f[N][N][M];

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		memset(f, 0, sizeof f);
		
		cin >> n >> c >> k;
		for (int i = 1; i <= n; i ++ ) f[i][0][1] = 1.0;
		
		for (int j = 0; j < k; j ++ )
		{
			int l, r;
			cin >> l >> r;
			
			for (int i = 1; i <= n; i ++ )
				for (int a = 0; a < c; a ++ )
					if (abs(f[i][j][a] - 0) < eps) continue;
					else
					{
						if (i < l || i > r) f[i][j + 1][a] += f[i][j][a];
						else
						{
							f[i][j + 1][a] += f[i][j][a] * 0.5;
							for (int b = 0; b < c; b ++ )
								f[i][j + 1][(a * b) % c] += f[i][j][a] / (2 * c);
						}
					}
		}
		
		double res = 0.0;
		for (int i = 1; i <= n; i ++ )
			for (int a = 0; a < c; a ++ )
				res += f[i][k][a] * a;
		cout << res << '\n';
	}
    return 0;
}
