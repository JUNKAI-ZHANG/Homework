#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("C:\\Users\\Administrator\\Desktop\\2021下\\软工\\prac2\\yq_in.txt", "r", stdin);
	freopen("C:\\Users\\Administrator\\Desktop\\2021下\\软工\\prac2\\out1.txt", "w", stdout);

	string s, ss;
	int num;
	map<string, vector<pair<string, int> >, greater<string> > mp;

	while(cin >> s >> ss >> num) {
		mp[s].push_back(pair<string, int>(ss, num));
	}
	for(auto it : mp) {
		cout << it.first << '\n';
		for(auto i : it.second) {
			cout << i.first << ' ' << i.second << '\n';
		}
		cout << '\n';
	}
	return 0;
}
