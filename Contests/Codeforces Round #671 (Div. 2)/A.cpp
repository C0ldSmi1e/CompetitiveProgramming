
// Problem : A. Digit Game
// Contest : Codeforces - Codeforces Round #671 (Div. 2)
// URL : https://codeforces.com/contest/1419/problem/A
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
int n;
string s;

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n >> s;
		vector<int> dig;
		if (n & 1)
		{
			for (int i = 0; i < SZ(s); i += 2) dig.PB(s[i] - '0');
		}
		else
		{
			for (int i = 1; i < SZ(s); i += 2) dig.PB(s[i] - '0');
		}
		
		bool odd = false, even = false;
		for (auto u : dig)
			if (u & 1) odd = true;
			else even = true;
		
		if (n & 1)
		{
			if (odd) cout << 1 << '\n';
			else cout << 2 << '\n';
		}
		else
		{
			if (even) cout << 2 << '\n';
			else cout << 1 << '\n';
		}
	}
    return 0;
}
