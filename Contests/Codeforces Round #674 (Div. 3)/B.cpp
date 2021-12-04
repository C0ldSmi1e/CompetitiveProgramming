
// Problem : B. Symmetric Matrix
// Contest : Codeforces - Codeforces Round #674 (Div. 3)
// URL : https://codeforces.com/contest/1426/problem/B
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

const int N = 4, M = 1010;

int T;
int n, m;
int a[N];

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n >> m;
		
		bool flag = false, ok = false;
		while (n -- )
		{
			for (int i = 0; i < N; i ++ ) cin >> a[i];
			if (a[1] == a[2]) flag = true;
		}
		
		if (m & 1) cout << "NO\n";
		else if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
    return 0;
}
