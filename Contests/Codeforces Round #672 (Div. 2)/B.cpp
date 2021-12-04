
// Problem : B. Rock and Lever
// Contest : Codeforces - Codeforces Round #672 (Div. 2)
// URL : https://codeforces.com/contest/1420/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define SZ(x) x.size()
#define EB emplace_back
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

LL C(LL a, LL b)
{
	return a * (a - 1) / 2LL;
}

int main()
{
	IOS

	cin >> T;
	while (T -- )
	{
		cin >> n;
		for (int i = 0; i < n; i ++ ) cin >> a[i];
		
		LL res = 0;
		for (int bit = 30; bit >= 0; bit -- )
		{
			int cnt = 0;
			for (int i = 0; i < n; i ++ )
				if ((a[i] >> bit) & 1)
				{
					bool flag = false;
					for (int j = 30; j >= 0; j -- )
						if ((a[i] >> j) & 1)
						{
							if (j == bit) flag = true;
							break;
						}
					if (flag) cnt ++ ;
				}
			res += C(cnt, 2);
		}
		cout << res << '\n';
	}
    return 0;
}
