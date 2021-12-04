
// Problem : D. Make Them Equal
// Contest : Codeforces - Codeforces Round #673 (Div. 2)
// URL : https://codeforces.com/contest/1417/problem/D
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

const int N = 100010, M = 1010;

int T;
int n, a[N];
vector<int> idx_i, idx_j, x;

void op(int i, int j, int tx)
{
	idx_i.EB(i);
	idx_j.EB(j);
	x.EB(tx);
	a[i] -= i * tx;
	a[j] += i * tx;
}

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n;
		
		int t = 0;
		for (int i = 1; i <= n; i ++ )
		{
			cin >> a[i];
			t += a[i];
		}
		
		if (t % n)
		{
			cout << "-1\n";
			continue;
		}
		else t /= n;
		
		idx_i.clear();
		idx_j.clear();
		x.clear();
	
		for (int i = 2; i <= n; i ++ )
		{
			if (a[i] % i) op(1, i, i - a[i] % i);
			op(i, 1, a[i] / i);
		}
		
		for (int i = 2; i <= n; i ++ ) op(1, i, t);
		
		cout << SZ(x) << '\n';
		for (int i = 0; i < SZ(x); i ++ )
			cout << idx_i[i] << ' ' << idx_j[i] << ' ' << x[i] << '\n';
	}
    return 0;
}
