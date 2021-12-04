#include <vector>
#include <iostream>

using namespace std;

int ask(int l, int r)
{
    cout << "? " << l << ' ' << r << endl;
    cin >> r;
    return r;
}

void answer(int x)
{
    cout << "! " << x << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, T;
    cin >> n >> T;
    vector<int> tr(1 << 20, -1);
    while (T -- )
    {
        int k;
        cin >> k;
        int l = 1, r = n, p = 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (tr[p << 1] == -1) tr[p << 1] = ask(l, mid);
            int zero = (mid - l + 1) - tr[p << 1];
            if (zero >= k)
            {
                r = mid;
                p = (p << 1);
            }
            else
            {
                k -= zero;
                p = ((p << 1) | 1);
                l = mid + 1;
            }
        }
        answer(r);
        while (p)
        {
            tr[p] ++ ;
            p = (p >> 1);
        }
    }
    return 0;
}
