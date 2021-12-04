
// Problem : F. Number of Subsequences
// Contest : Codeforces - Codeforces Round #674 (Div. 3)
// URL : https://codeforces.com/contest/1426/problem/F
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

const int N = 200010, M = 5, mod = 1e9 + 7;

int n;
int f[N][M][M];
string s;

int qp(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = (LL)res * a % mod;
		a = (LL)a * a % mod;
		b >>= 1;
	}
	return res;
}

int main()
{
	IOS
	
	cin >> n >> s;
	
	int cnt = 0;
	for (auto u : s) cnt += u == '?';
	
	f[0][0][0] = 1;
	for (int i = 0; i < n; i ++ )
		for (int j = 0; j <= 3; j ++ )
			for (int k = 0; k <= 3; k ++ )
				if (f[i][j][k])
				{
					f[i + 1][j][k] = (f[i + 1][j][k] + f[i][j][k]) % mod;
					if (k < 3 && (s[i] == '?' || s[i] == 'a' + j))
					{
						int t = s[i] == '?' ? 1 : 0;
						f[i + 1][j + 1][k + t] = (f[i + 1][j + 1][k + t] + f[i][j][k]) % mod;
					}
				}
	
	int res = 0;
	for (int i = 0; i <= 3; i ++ )
		if (cnt >= i)
			res = (res + (LL)f[n][3][i] * qp(3, cnt - i) % mod) % mod;
			
	cout << res << '\n';
    return 0;
}
