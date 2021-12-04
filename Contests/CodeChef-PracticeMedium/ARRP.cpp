
// Problem : Partitions
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/ARRP
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

const int N = 1000010, M = 1010, INF = 0x3f3f3f3f;

int T;
int n;
LL a[N], res[N];

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n;
		
		for (int i = 1; i <= n; i ++ ) res[i] = 0;
		
		LL sum = 0, maxa = -INF;
		for (int i = 1; i <= n; i ++ )
		{
			cin >> a[i];
			sum += a[i];
			maxa = max(maxa, a[i]);
		}
		
		for (int cnt = 1; cnt <= n; cnt ++ )
			if (sum % cnt == 0 && sum / cnt >= maxa)
			{
				bool flag = true;
				LL per_sum = sum / cnt;
				for (int i = 1; i <= n; i ++ )
				{
					LL tsum = 0;
					int j = i;
					while (j <= n && a[j] + tsum <= per_sum)
					{
						tsum += a[j];
						j ++ ;
					}

					if (tsum != per_sum)
					{
						flag = false;
						break;
					}
					i = j - 1;
				}
				if (flag) res[cnt] = 1;
			}
		
		for (int i = 1; i <= n; i ++ ) cout << res[i];
		cout << '\n';
	}
    return 0;
}
