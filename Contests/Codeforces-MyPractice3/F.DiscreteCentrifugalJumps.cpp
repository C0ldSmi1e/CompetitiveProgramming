#include <iostream>

using namespace std;

const int N = 300010;

int n;
int h[N];
int f[N];
int top1, top2;
int stk1[N], stk2[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> h[i];
    stk1[ ++ top1] = 1;
    stk2[ ++ top2] = 1;
    f[1] = 0;
    for (int i = 2; i <= n; i ++ )
    {
        f[i] = min(f[i - 1] + 1, i - 1);
        int last = -1;
        while (top1 && h[stk1[top1]] >= h[i])
        {
            last = stk1[top1];
            f[i] = min(f[i], f[stk1[top1]] + 1);
            top1 -- ;
        }
        if (top1 && last != -1 && h[i] != h[last]) f[i] = min(f[i], f[stk1[top1]] + 1);
        stk1[ ++ top1] = i;
        last = -1;
        while (top2 && h[stk2[top2]] <= h[i])
        {
            last = stk2[top2];
            f[i] = min(f[i], f[stk2[top2]] + 1);
            top2 -- ;
        }
        if (top2 && last != -1 && h[i] != h[last]) f[i] = min(f[i], f[stk2[top2]] + 1);
        stk2[ ++ top2] = i;
    }
    cout << f[n] << '\n';
    return 0;
}
