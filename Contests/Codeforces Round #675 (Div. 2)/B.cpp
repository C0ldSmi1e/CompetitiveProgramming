
// Problem: B. Nice Matrix
// Contest: Codeforces - Codeforces Round #675 (Div. 2)
// URL: https://codeforces.com/contest/1422/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

// check the limitation!!!
const int N = 110, M = 1010;

int T;
int n, m;

// read the question carefully!!!
int main()
{
	/*
		1+9+18+4=32 -> 8*4=32 -> 7+1+10+4=22 8+5+9=22
		2+3+10+11=26 -> 6*4=24 -> 4+3+4+5=16 1+7+8=16
		6+7=13 -> 6*2=12 -> 1 
		5+8=13 -> 6*2=12 -> 3
		22+16+1+3=42
	*/
	
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n >> m;
		vector<vector<int>> a(n + 1, vector<int>(m + 1));
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= m; j ++ )
				cin >> a[i][j];
		
		vector<vector<bool>> st(n + 1, vector<bool>(m + 1, false));
		vector<vector<int>> g;
		
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= m; j ++ )
				if (!st[i][j])
				{
					vector<int> t;
					t.EB(a[i][j]);
					st[i][j] = true;
					if (!st[i][m - j + 1])
					{
						t.EB(a[i][m - j + 1]);
						st[i][m - j + 1] = true;
					}
					if (!st[n - i + 1][j])
					{
						t.EB(a[n - i + 1][j]);
						st[n - i + 1][j] = true;
					}
					if (!st[n - i + 1][m - j + 1])
					{
						t.EB(a[n - i + 1][m - j + 1]);
						st[n - i + 1][m - j + 1] = true;
					}
					g.EB(t);
				}
			
		LL res = 0;	
		for (auto b : g)
		{
			sort(ALL(b));
			int mid = SZ(b) / 2;
			for (auto u : b) res += abs(u - b[mid]);
		}
		cout << res << '\n';
	}
    return 0;
}