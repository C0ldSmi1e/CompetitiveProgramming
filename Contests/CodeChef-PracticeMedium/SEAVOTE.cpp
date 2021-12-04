
// Problem : Sereja and Votes
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/SEAVOTE
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

const int N = 100010, M = 1010;

int T;
int n;

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n;
		int l = 0, r = 0;
		for (int i = 0; i < n; i ++ )
		{
			int x;
			cin >> x;
			l += max(0, x - 1);
			r += x;
		}
		if (l <= 100 && r >= 100) puts("YES");
		else puts("NO");
	}		
    return 0;
}
