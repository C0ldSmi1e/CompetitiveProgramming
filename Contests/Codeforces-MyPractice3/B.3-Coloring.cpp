#include <vector>
#include <iostream>
#include <algorithm>

#define F first
#define S second

using namespace std;

typedef pair<int, int> PII;

int main()
{
    int n;
    cin >> n;
    vector<PII> g[2];
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            g[(i + j) & 1].emplace_back(i, j);
    auto answer = [&](int b, int x, int y)
    {
        cout << b + 1 << ' ' << x + 1 << ' ' << y + 1 << '\n';
    };
    auto ask = [&]() -> int
    {
        int x;
        cin >> x;
        return x - 1;
    };
    for (int i = 0; i < n * n; i ++ )
    {
        int c = ask();
        int b = -1, t = -1;
        if (c == 0)
        {
            if (g[1].size()) t = 1, b = 1;
            else t = 0, b = 2;
        }
        else if (c == 1)
        {
            if (g[0].size()) t = 0, b = 0;
            else t = 1, b = 2;
        }
        else if (c == 2)
        {
            if (g[0].size()) t = 0, b = 0;
            else t = 1, b = 1;
        }
        answer(b, g[t].back().F, g[t].back().S);
        g[t].pop_back();
    }
    return 0;
}
