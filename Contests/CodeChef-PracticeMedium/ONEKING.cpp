
// Problem : One Dimensional Kingdoms
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/ONEKING
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

const int N = 100010, M = 1010;

int T;
int n;
PII a[N];

bool cmp(PII a, PII b)
{
	if (a.S != b.S) return a.S < b.S;
	else return a.F > b.F;
}

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n;
		for (int i = 0; i < n; i ++ ) cin >> a[i].F >> a[i].S;
		sort(a, a + n, cmp);
		
		int res = 0, pos = -0x3f3f3f3f;
		for (int i = 0; i < n; i ++ )
			if (a[i].F > pos)
		    {
		        pos = a[i].S;
		        res ++ ;
		    }
		cout << res << '\n';
	}
    return 0;
}
