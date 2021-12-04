
// Problem : Chef and Reunion
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/LPAIR
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

int n;
PII a[N], t[N];

LL merge_sort(int l, int r)
{
	if (l >= r) return 0;
	
	int mid = l + r >> 1;
	LL res = merge_sort(l, mid) + merge_sort(mid + 1, r);
	
	int i = l, j = mid + 1, k = l;
	while (i <= mid && j <= r)
		if (a[i].S <= a[j].S) t[k ++ ].S = a[i ++ ].S;
		else
		{
			res += mid - i + 1;
			t[k ++ ].S = a[j ++ ].S;
		}
	while (i <= mid) t[k ++ ].S = a[i ++ ].S;
	while (j <= r) t[k ++ ].S = a[j ++ ].S;
	
	for (int i = l; i <= r; i ++ ) a[i].S = t[i].S;
	return res;
}

int main()
{
	IOS
	
	cin >> n;
	for (int i = 0; i < n; i ++ ) cin >> a[i].F >> a[i].S;
	sort(a, a + n);
	
	printf("%lld\n", merge_sort(0, n - 1));
    return 0;
}
