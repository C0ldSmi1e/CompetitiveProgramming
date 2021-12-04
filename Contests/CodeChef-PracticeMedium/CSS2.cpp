
// Problem : Cascading Style Sheets
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/CSS2
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

const int N = 1000010, M = 1010;

int n, m;
map<int, PII> h[N];

int main()
{
	IOS
	
	cin >> n >> m;
	for (int i = 0; i < n; i ++ )
	{
		int id, attr, val, priority;
		cin >> id >> attr >> val >> priority;
		if (!h[id].count(attr)) h[id][attr] = {val, priority};
		else
		{
			if (h[id][attr].S <= priority)
				h[id][attr] = {val, priority};
		}
	}
	
	for (int i = 0; i < m; i ++ )
	{
		int id, attr;
		cin >> id >> attr;
		cout << h[id][attr].F << '\n';
	}
    return 0;
}
