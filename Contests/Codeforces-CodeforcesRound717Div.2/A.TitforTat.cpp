/**
 * Author: Daniel
 * Created Time: 2021-04-22 12:25:43
**/

#include <vector>
#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T -- ) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &u : a) {
            cin >> u;
        }
        for (int i = 0; i < n - 1; i ++ ) {
            while (k && a[i]) {
                k -- ;
                a[i] -- ;
                a.back() ++ ;
            }
        }
        for (auto &u : a) {
            cout << u << ' ';
        }
        cout << '\n';
    }
    return 0;
}
