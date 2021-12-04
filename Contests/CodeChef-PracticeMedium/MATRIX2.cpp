
// Problem : Matrix
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/MATRIX2
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

const int N = 2010, M = 1010;

int n, m;
int g[N][N], len[N][N];
LL f[N][N];

int main()
{
	IOS
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j ++ )
			g[i][j + 1] = s[j] - '0';
	}
	
	for (int j = 1; j <= m; j ++ )
		for (int i = 1; i <= n; i ++ )
			if (g[i][j]) len[i][j] = len[i - 1][j] + 1;
	
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
			f[i][j] = min(f[i - 1][j - 1] + 1, (LL)len[i][j]);
	
	LL res = 0;
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
			res += f[i][j];
	cout << res <<'\n';
    return 0;
}
