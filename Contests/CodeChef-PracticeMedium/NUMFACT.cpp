
// Problem : Number of Factors
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/NUMFACT
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

const int N = 500010, M = 1010;

int T;
int n;

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n;
		map<int, LL> h;
		for (int i = 0; i < n; i ++ )
		{
			int x;
			cin >> x;
			
			for (int j = 2; j <= x / j; j ++ )
				while (x % j == 0)
				{
					h[j] ++ ;
					x /= j;
				}
			if (x > 1) h[x] ++ ;
		}
		
		LL res = 1;
		for (auto u : h) res *= (u.S + 1LL);
		cout << res << '\n';
	}
    return 0;
}
