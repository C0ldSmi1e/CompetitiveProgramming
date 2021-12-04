/**
*  Author: Daniel
*  Created Time: 2020-10-24 14:09:02
**/

// time-limit: 2000
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

int n, a[N];
int two_match[N];
bool st[N];
vector<PII> res;

// read the question carefully!!!
int main()
{
    IOS

    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    vector<int> three;
    for (int i = 1; i <= n; i ++ )
        if (a[i] == 3)
            three.EB(i);

    
    int three_rst = 0;
    if (SZ(three))
    {
        for (int i = n; i > three.back(); i -- )
            if (a[i] == 2)
            {
                three_rst = i;
                break;
            }
        if (!three_rst)
        {
            for (int i = n; i > three.back(); i -- )
                if (a[i] == 1)
                {
                    three_rst = i;
                    break;
                }
        }
        if (!three_rst)
        {
            cout << "-1\n";
            return 0;
        }
    }


    vector<int> one;
    for (int i = n; i >= 1; i -- )
        if (a[i] == 1 && i != three_rst) one.EB(i);
        else if (a[i] == 2)
        {
            if (!SZ(one))
            {
                cout << "-1\n";
                return 0;
            }
            else
            {
                two_match[i] = one.back();
                one.PB();
            }
        }

    
    int row = 0;
    if (SZ(three))
    {
        for (int i = 0; i < SZ(three); i ++ )
        {
            if (i) res.EB(MP(row, three[i]));
            row ++ ;
            res.EB(MP(row, three[i]));
            st[three[i]] = true;
        }
        res.EB(MP(row, three_rst));
        row ++ ;
        res.EB(MP(row, three_rst));
        st[three_rst] = true;

        if (a[three_rst] == 2)
        {
            int col = two_match[three_rst];
            res.EB(MP(row, col));
            st[col] = true;
        }
    }

    for (int i = 1; i <= n; i ++ )
        if (!st[i])
        {
            row ++ ;
            if (a[i] == 1)
            {
                res.EB(MP(row, i));
                st[i] = true;
            }
            else if (a[i] == 2)
            {
                res.EB(MP(row, i));
                res.EB(MP(row, two_match[i]));
                st[i] = st[two_match[i]] = true;
            }
        }

    cout << SZ(res) << '\n';
    for (auto u : res) cout << u.F << ' ' << u.S << '\n';
    return 0;
}
