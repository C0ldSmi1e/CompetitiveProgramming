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
const int N = 1000010, M = 1010;


int n, k;
int a[N];

LL get(LL len, LL part)
{
    LL len1 = len / part;
    LL len2 = len1 + 1;
    LL cnt1 = part - len % part;
    LL cnt2 = len % part;
    return cnt1 * len1 * len1 + cnt2 * len2 * len2;
}

struct Carrot
{
    LL len, part;
    LL cut() const 
    {
        return get(len, part) - get(len, part + 1);
    }
    bool operator<(const Carrot &t) const
    {
        return cut() > t.cut();
    }
};

multiset<Carrot> S;

// read the question carefully!!!
int main()
{
    IOS

    cin >> n >> k;
    for (int i = 0; i < n; i ++ )
    {
        cin >> a[i];
        Carrot c = {a[i], 1};
        S.IS(c);
    }

    while (n < k)
    {
        Carrot c = *S.begin();
        S.erase(S.begin());
        Carrot tc = {c.len, c.part + 1};
        S.IS(tc);
        n ++ ;
    }

    LL res = 0;
    for (auto u : S) res += get(u.len, u.part);
    cout << res << '\n';
    return 0;
}
