
// Problem : Dual Nim
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/TWONIM
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

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n;
		int t = 0;
		for (int i = 0; i < n; i ++ )
		{
			cin >> a[i];
			t ^= a[i];
		}
		
		if (!t) cout << "First" << '\n';
		else
		{
			if (n & 1) cout << "Second" << '\n';
			else cout << "First" << '\n';
		}
	}
    return 0;
}
