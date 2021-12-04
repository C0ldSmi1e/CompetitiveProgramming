
// Problem : Mahesh and his lost array
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/ANUMLA
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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

const int N = 510, M = 1010;

int T;
int n, m;

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n;
		m = 1 << n;
		vector<int> a(m);
		
		for (auto &u : a) cin >> u;
		sort(ALL(a));
		
		vector<int> c(m), res(n);
		int ri = 0, ci = 0;
		MSET MS;
		
		for (int i = 1; i < m; i ++ )
		{
			int t = -1;
			if (MS.size()) t = *MS.begin();
			
			if (a[i] == t) MS.erase(MS.begin());
			else
			{
				int tci = ci;
				for (int j = 0; j < tci; j ++ )
				{
					c[ci] = a[i] + c[j];
					MS.IS(c[ci]);
					ci ++ ;
				}
				c[ci ++ ] = a[i];
				res[ri ++ ] = a[i];
			}
		}
		
		for (auto &u : res) cout << u << ' ';
		cout << '\n';
	}
    return 0;
}
