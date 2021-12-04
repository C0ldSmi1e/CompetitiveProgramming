
// Problem : A. Floor Number
// Contest : Codeforces - Codeforces Round #674 (Div. 3)
// URL : https://codeforces.com/contest/1426/problem/A
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
int n, x;

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n >> x;
		if (n <= 2) cout << "1\n";
		else cout << (n - 2 + x - 1) / x + 1 << '\n';
	}
    return 0;
}
