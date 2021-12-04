/**
*  Author: Daniel
*  Created Time: 2020-10-12 17:42:16
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
const int N = 100010, M = 1010, INF = 0x3f3f3f3f;

int T;
int n, k;
char s[N];

// read the question carefully!!!
int main()
{
    IOS

    cin >> T;
    while (T -- )
    {
        cin >> n >> k >> s;

        int cnt_w = 0, cnt_l = 0;
        for (int i = 0; i < n; i ++ )
            if (s[i] == 'W') cnt_w ++ ;
            else cnt_l ++ ;

        if (k >= cnt_l)
        {
            cout << 2 * n - 1 << '\n';
            continue;
        }
        else if (!cnt_w)
        {
            cout << max(0, 2 * k - 1) << '\n';
            continue;
        }

        int head_w = 0;
        for (int i = 0; i < n; i ++ )
            if (s[i] == 'W' && (!i || s[i - 1] == 'L'))
                head_w ++ ;

        vector<int> seq_l;
        for (int i = 0; i < n; i ++ )
        {
            int j = i;
            while (j < n && s[j] == 'L') j ++ ;
            if (j - i) seq_l.EB(j - i);
            i = j;
        }

        if (s[0] == 'L') seq_l[0] = INF;
        if (s[n - 1] == 'L') seq_l.back() = INF;
        sort(ALL(seq_l));

        int res = 2 * (cnt_w + k);
        for (auto u : seq_l)
            if (k >= u)
            {
                k -= u;
                head_w -- ;
            }
        cout << res - head_w << '\n';
    }
    return 0;
}
