
// Problem : Mixtures
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/MIXTURES
// Memory Limit : 256 MB
// Time Limit : 0 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB push_back
#define SZ(x) x.size()
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef multiset<int> MSET;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 110, M = 1010;

int n, a[N];
int f[N][N];
int s[N];

int sum(int l, int r)
{
	return (s[r] - s[l - 1]) % 100;
}

int main()
{
	IOS

	while (cin >> n)
	{
		for (int i = 1; i <= n; i ++ )
		{
			cin >> a[i];
			s[i] = a[i] + s[i - 1];
		}
		
		memset(f, 0x3f, sizeof f);
		for (int i = 1; i <= n; i ++ ) f[i][i] = 0;
		
		for (int len = 2; len <= n; len ++ )
			for (int l = 1; l + len - 1 <= n; l ++ )
			{
				int r = l + len - 1;
				for (int k = l; k <= r - 1; k ++ )
					f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + sum(l, k) * sum(k + 1, r));
			}
		
		cout << f[1][n] << '\n';
	}
    return 0;
}
