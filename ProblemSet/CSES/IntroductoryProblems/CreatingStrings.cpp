#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	string s;
	cin >> s;
	int n = (int)s.size();
	set<string> S;
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(s.begin(), s.end());
	do
	{
	    string t(n, '#');
	    for (int i = 0; i < n; i ++ ) t[i] = s[order[i]];
		S.insert(t);
	} while (next_permutation(order.begin(), order.end()));
	cout << (int)S.size() << '\n';
	for (auto &u : S) cout << u << '\n';
	return 0;
}
