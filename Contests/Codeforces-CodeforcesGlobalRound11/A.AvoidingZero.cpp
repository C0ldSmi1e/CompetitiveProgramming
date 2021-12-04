/**
*  Author: Daniel
*  Created Time: 2020-10-12 13:47:00
**/

// time-limit: 1000
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
const int N = 100010, M = 1010;

int T;
int n;
int a[N];

// read the question carefully!!!
int main()
{
    IOS
    
    cin >> T;
    while (T -- )
    {
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; i ++ )
        {
            cin >> a[i];
            sum += a[i];
        }

        if (!sum) cout << "NO\n";
        else
        {
            cout << "YES\n";
            sort(a, a + n);
            if (sum > 0)
                for (int i = n - 1; i >= 0; i -- )
                    cout << a[i] << ' ';
            else 
                for (int i = 0; i < n; i ++ )
                    cout << a[i] << ' ';
            cout << '\n';
        }
    }
    return 0;
}
