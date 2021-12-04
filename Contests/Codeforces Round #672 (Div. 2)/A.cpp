
// Problem : A. Cubes Sorting
// Contest : Codeforces - Codeforces Round #672 (Div. 2)
// URL : https://codeforces.com/contest/1420/problem/A
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
int t[N];

LL merge_sort(int l, int r)
{
    if (l >= r) return 0;
    
    int mid = l + r >> 1;
    LL res = merge_sort(l, mid) + merge_sort(mid + 1, r);
    
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
        if (a[i] <= a[j]) t[k ++ ] = a[i ++ ];
        else
        {
            res += mid - i + 1;
            t[k ++ ] = a[j ++ ];
        }
    
    while (i <= mid) t[k ++ ] = a[i ++ ];
    while (j <= r) t[k ++ ] = a[j ++ ];
    
    for (int i = l; i <= r; i ++ ) a[i] = t[i];
    return res;
}

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n;
		for (int i = 0; i < n; i ++ ) cin >> a[i];
		
		LL cnt = merge_sort(0, n - 1);
		
		if (cnt > ((LL)n * (n - 1LL)) / 2LL - 1LL) cout << "NO\n";
		else cout << "YES\n";
	}
    return 0;
}
