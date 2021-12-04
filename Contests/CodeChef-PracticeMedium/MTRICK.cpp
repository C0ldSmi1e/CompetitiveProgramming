
// Problem : Magic Trick
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/MTRICK
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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

const int N = 1010, M = 1010;

int T;
int n;
LL a[N], A, B, C;
char s[N];

LL mul(LL a, LL b, LL mod)
{
	LL res = 0;
	while (b)
	{
		if (b & 1) res = (res + a) % mod;
		a = a * 2 % mod;
		b >>= 1;
	}
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
		cin >> A >> B >> C >> s;
		
		int st = 0, ed = n - 1, rotate = 0;
		LL ADD = 0, MUL = 1;
		for (int i = 0; i < n; i ++ )
		{
			if (s[i] == 'A') ADD = (ADD + A) % C;
			else if (s[i] == 'M')
			{
				ADD = mul(ADD, B, C);
				MUL = mul(MUL, B, C);
			}
			else rotate ^= 1;
			
			if (!rotate)
			{
				cout << (mul(a[st], MUL, C) + ADD) % C << ' ';
				st ++ ;
			}
			else
			{
				cout << (mul(a[ed], MUL, C) + ADD) % C << ' ';
				ed -- ;
			}
		}
		cout << '\n';
	}
    return 0;
}
