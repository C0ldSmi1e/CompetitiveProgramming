
// Problem : Pouring water
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/POUR1
// Memory Limit : 256 MB
// Time Limit : 190 ms
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

const int N = 100010, M = 1010;

int T;
int a, b, c;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int get(int a, int b, int c)
{
	int A = a, B = 0, cnt = 1;
	while (true)
	{
		int t = min(A, b - B);
		A -= t, B += t, cnt ++ ;
		if (A == c || B == c) break;
		if (A == 0)
		{
			A = a;
			cnt ++ ;
		}
		if (B == b)
		{
			B = 0;
			cnt ++ ;
		}
	}
	return cnt;
}

int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> a >> b >> c;
		if (c > a && c > b || c % gcd(a, b)) cout << -1 << '\n';
		else if (a == c || b == c) cout << 1 << '\n';
		else cout << min(get(a, b, c), get(b, a, c)) << '\n';
	}
    return 0;
}
