
// Problem : C. Killjoy
// Contest : Codeforces - Codeforces Round #671 (Div. 2)
// URL : https://codeforces.com/contest/1419/problem/C
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
int n, x;
int a[N];

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n >> x;
		int sum = 0;
		bool same = true, flag = false;
		for (int i = 0; i < n; i ++ )
		{
			cin >> a[i];
			sum += x - a[i];
			if (a[i] != x) same = false;
			else flag = true; 
		}
		
		if (same) cout << "0\n";
		else if (flag || !sum) cout << "1\n";
		else cout << "2\n";
	}
    return 0;
}
