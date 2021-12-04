
// Problem: A. Number of Apartments
// Contest: Codeforces - Educational Codeforces Round 96 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1430/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

// check the limitation!!!
const int N = 100010, M = 1010;

int T;
int n;

// read the question carefully!!!
int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n;
		bool flag = false;
		for (int i = 0; !flag && 3 * i <= n; i ++ )
			for (int j = 0; !flag && 3 * i + 5 * j <= n; j ++ )
			{
				int left = n - 3 * i - 5 * j;
				if (left >= 0 && left % 7 == 0)
				{
					cout << i << ' ' << j << ' ' << left / 7 << '\n';
					flag = true;
				}
			}
		if (!flag) cout << "-1\n";
	}
    return 0;
}

