
// Problem: A. Circle Coloring
// Contest: Codeforces - Grakn Forces 2020
// URL: https://codeforces.com/contest/1408/problem/A
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
const int N = 110, M = 1010;

int T;
int n;
int a[N], b[N], c[N];

// read the question carefully!!!
int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n;
		for (int i = 0; i < n; i ++ ) cin >> a[i];
		for (int i = 0; i < n; i ++ ) cin >> b[i];
		for (int i = 0; i < n; i ++ ) cin >> c[i];
		
		vector<int> res(n);
		res[0] = a[0];
		
		for (int i = 1; i < n - 1; i ++ )
			if (a[i] == res[i - 1]) res[i] = b[i];
			else res[i] = a[i];
		
		if (a[n - 1] != res[n - 2] && a[n - 1] != res[0]) res[n - 1] = a[n - 1];
		else if (b[n - 1] != res[n - 2] && b[n - 1] != res[0]) res[n - 1] = b[n - 1];
		else if (c[n - 1] != res[n - 2] && c[n - 1] != res[0]) res[n - 1] = c[n - 1];
		
		for (auto u : res) cout << u << ' ';
		cout << '\n';
	}
    return 0;
}