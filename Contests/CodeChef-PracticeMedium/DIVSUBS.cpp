
// Problem : Divisible Subset
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/DIVSUBS
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

const int N = 100010, M = 1010;

int T;
int n, a[N];
LL s[N];

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n;
		for (int i = 1; i <= n; i ++ )
		{
			cin >> a[i];
			s[i] = s[i - 1] + a[i];
		}
		
		int l, r;
		map<int, int> h;
		h[0] = 0;
		
		for (int i = 1; i <= n; i ++ )
		{
			int rem = s[i] % n;
			if (h.count(rem))
			{
				l = h[rem] + 1;
				r = i;
				break;
			}
			h[rem] = i;
		}
		
		cout << r - l + 1 << '\n';
		for (int i = l; i <= r; i ++ ) cout << i << ' ';
		cout << '\n';
	}
    return 0;
}
