/**
 * Author: Daniel
 * Created Time: 2021-06-17 12:13:05
**/

#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
vector<int> p;
 
int find(int x) {
  if (x != p[x]) p[x] = find(p[x]);
  return p[x];
}
 
int main() {
  cin >> n >> m;
  p.resize(n);
  iota(p.begin(), p.end(), 0);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    int pa = find(a), pb = find(b);
    p[pa] = pb;
  }
  vector<int> root;
  for (int i = 0; i < n; i++) {
    if (p[i] == i) {
      root.push_back(i);
    }
  }
  cout << (int) root.size() - 1 << '\n';
  for (int i = 0; i < (int) root.size() - 1; i++) {
    cout << root[i] + 1 << ' ' << root[i + 1] + 1 << '\n';
  }
  return 0;
}
