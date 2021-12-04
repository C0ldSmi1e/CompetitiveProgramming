
// Problem : Polo the Penguin and the XOR
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/PPXOR
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

const int N = 100010, M = 35;

int T;
int n, a[N];
int s[N], cnt[M];

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		memset(cnt, 0, sizeof cnt);
		cin >> n;
		for (int i = 1; i <= n; i ++ )
		{
			cin >> a[i];
			s[i] = s[i - 1] ^ a[i];
		}
		
		LL res = 0;
		for (int i = 1; i <= n; i ++ )
			for (int j = 0; j < 30; j ++ )
			{
				if ((s[i] >> j) & 1) res += (1 << j) * (LL)(i - cnt[j]);
				else res += (1 << j) * (LL)cnt[j];
				cnt[j] += (s[i] >> j) & 1;
			}
		cout << res << '\n';
	}
    return 0;
}
