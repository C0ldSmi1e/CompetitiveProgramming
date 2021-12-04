
// Problem : Little Elephant and T-Shirts
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/TSHIRTS
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
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef multiset<int> MSET;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 1 << 10, M = 110, mod = 1e9 + 7;

int T;
int n;
int f[N][M];
bool st[M][M];

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		memset(f, 0, sizeof f);
		memset(st, 0, sizeof st);
		
        cin >> n;
        
        int t;
        string ss;
        
        getline(cin, ss);
		for (int i = 0; i < n; i ++ )
		{
			getline(cin, ss);
			stringstream s(ss);
			while (s >> t) st[i][t] = true;
		}
		
		f[0][0] = 1;
		for (int i = 0; i < 1 << n; i ++ )
			for (int j = 1; j <= 100; j ++ )
			{
				f[i][j] = f[i][j - 1];
				for (int k = 0; k < n; k ++ )
					if (((i >> k) & 1) && st[k][j])
						f[i][j] = (f[i][j] + f[i ^ (1 << k)][j - 1]) % mod;
			}
		cout << f[(1 << n) - 1][100] << '\n';
	}
    return 0;
}
