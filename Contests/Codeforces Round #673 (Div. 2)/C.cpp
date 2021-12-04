
// Problem : C. k-Amazing Numbers
// Contest : Codeforces - Codeforces Round #673 (Div. 2)
// URL : https://codeforces.com/contest/1417/problem/C
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

// check the limitation!!!
const int N = 300010, M = 1010;

int T;
int n, a[N];

// read the question carefully!!!
int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n;
		
		vector<int> res(n + 1, -1), pos[n + 5];
		
		for (int i = 1; i <= n; i ++ ) pos[i].EB(0);
		
		for (int i = 1; i <= n; i ++ )
		{
			cin >> a[i];
			pos[a[i]].EB(i);
		}
		
		for (int i = 1; i <= n; i ++ )
		{
			int maxa = 0;
			pos[i].EB(n + 1);
			
			for (int j = 0; j < SZ(pos[i]) - 1; j ++ )
				maxa = max(maxa, pos[i][j + 1] - pos[i][j]);
			
			if (maxa != n + 1 && res[maxa] == -1) res[maxa] = i;
		}
		
		for (int i = 1; i <= n; i ++ )
			if (res[i - 1] != -1)
			{
				if (res[i] == -1) res[i] = res[i - 1];
				else res[i] = min(res[i], res[i - 1]);
			}
		
		for (int i = 1; i <= n; i ++ ) cout << res[i] << ' ';
		cout << '\n';
	}
    return 0;
}
