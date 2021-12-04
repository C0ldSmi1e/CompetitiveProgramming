#include <iostream>
#include <algorithm>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;

const int N = 100010;
const LL mod = 1e9 + 7;

int n;
LL h[N], w[N];
int top;
PLL stk[N];

LL calc(LL h, LL w)
{
    h %= mod;
    w %= mod;
    return (((h + 1) * h / 2) % mod) * (((w + 1) * w / 2) % mod) % mod;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> h[i];
    for (int i = 0; i < n; i ++ ) cin >> w[i];
    n ++ ;
    LL res = 0;
    for (int i = 0; i < n; i ++ )
    {
        LL width = 0;
        while (top && stk[top].F > h[i])
        {
            width += stk[top].S;
            res = (res + calc(stk[top].F, width)) % mod;
            res = (res - calc(stk[top].F, width - stk[top].S)) % mod;
            top -- ;
        }
        res = (res - calc(h[i], width)) % mod;
        width += w[i];
        stk[ ++ top] = {h[i], width};
    }
    cout << (res % mod + mod) % mod;
    return 0;
}
