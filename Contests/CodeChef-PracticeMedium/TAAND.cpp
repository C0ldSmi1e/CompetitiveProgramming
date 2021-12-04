
// Problem : And Operation
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/TAAND
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

const int N = 300010, M = 1010;

int n;
int a[N];
set<int> S;

int main()
{
	IOS
	
	cin >> n;
	for (int i = 0; i < n; i ++ )
	{
		cin >> a[i];
		S.IS(i);
	}
	
	int res = 0;
	for (int bit = 30; bit >= 0; bit -- )
	{
		int cnt = 0;
		
		for (auto u : S)
			if ((a[u] >> bit) & 1)
				cnt ++ ;
		
		if (cnt <= 1) continue;
		res += 1 << bit;
		
		vector<int> del;
		for (auto u : S)
			if (!((a[u] >> bit) & 1))
				del.PB(u);
		
		for (auto u : del) S.erase(u);
	}
	cout << res << '\n';
    return 0;
}
