
// Problem : Pairwise AND sum
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/AND
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

const int N = 30, M = 1010;

int n;
int cnt[N];

int main()
{
	IOS
	
	cin >> n;
	for (int i = 0; i < n; i ++ )
	{
		int x;
		cin >> x;
		for (int j = 0; j < N; j ++ )
			if ((x >> j) & 1)
				cnt[j] ++ ;
	}
	
	LL res = 0;
	for (int i = 0; i < N; i ++ )
		if (cnt[i] > 1)
		{
			LL t = 1LL << i;
			res += t * (LL)cnt[i] * (cnt[i] - 1) / 2LL;
		}
	cout << res << '\n';
    return 0;
}
