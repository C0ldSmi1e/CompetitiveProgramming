
// Problem: D. String Deletion
// Contest: Codeforces - Educational Codeforces Round 96 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1430/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const int N = 200010, M = 1010;

int T;
int n;
char s[N];

// read the question carefully!!!
int main()
{
	IOS
	
	cin >> T;
	while (T -- )
	{
		cin >> n >> s;
		vector<int> seq;
		for (int i = 0; i < n; i ++ )
		{
			int j = i;
			while (j < n && s[j] == s[i]) j ++ ;
			seq.EB(j - i);
			i = j - 1;
		}
		
		int res = 0;
		for (int i = 0, j = 0; i < SZ(seq); i ++ , j ++ )
			if (seq[i] > 1) res ++ ;
			else
			{
				while (j < SZ(seq) && seq[j] == 1) j ++ ;
				if (j == SZ(seq))
				{
					res += (j - i + 1) / 2;
					break;
				}
				else
				{
					int len = j - i;
					if (seq[j] - len > 1)
					{
						res += len + 1;
						i = j;
					}
					else
					{
						res += seq[j] - 1;
						i += seq[j] - 2;
						seq[j] = 1;
					}
				}
			}
		cout << res << '\n';
	}
    return 0;
}

