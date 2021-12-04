
// Problem : Chef and easy problem 2
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/CHEFB
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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

const int N = 100010, M = 1000010;

int T;
int n;
int f[M];

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n;
		memset(f, 0, sizeof f);
		
		for (int i = 0; i < n; i ++ )
		{
			int x;
			cin >> x;
			for (int j = 2; j <= x / j; j ++ )
				if (x % j == 0)
				{
					int cnt = 0;
					while (x % j == 0)
					{
						x /= j;
						cnt ++ ;
					}
					f[j] = max(f[j], cnt);
				}
			if (x > 1) f[x] = max(f[x], 1);
		}
		
		LL res = 0;
		for (int i = 0; i < M; i ++ ) res += f[i];
		cout << res << '\n';
	}
    return 0;
}
