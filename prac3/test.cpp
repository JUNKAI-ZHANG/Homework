#include <iostream>
#include <map> 
#include <vector>
#include <cstdio>
#include <string.h>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	map<string, vector<pair<string, int > > > mp;
	string s, ss;
	string stdName = "";
	if(argc == 4) for(int i = 0;i < strlen(argv[3]);i++) stdName += argv[3][i];
	int x;
	string add1 = "C:\\Users\\Administrator\\Desktop\\2021\\prac3\\";
	string add2 = "C:\\Users\\Administrator\\Desktop\\2021\\prac3\\";
	char add11[100];
	char add22[100];
	for(int i = 0;i < 99;i++) add11[i] = add22[i] = 0;	
	for(int i = 0;i < strlen(argv[1]);i++) add1 += argv[1][i];
	for(int i = 0;i < strlen(argv[2]);i++) add2 += argv[2][i];
	for(int i = 0;i < add1.size();i++)     add11[i] = add1[i];
	for(int i = 0;i < add2.size();i++)     add22[i] = add2[i];

	freopen(add11, "r", stdin);	
	freopen(add22, "w", stdout);

	while(cin >> s >> ss >> x) mp[s].push_back(pair<string, int>(ss, x));
	map<string, vector<pair<string, int> > > :: iterator it;
	if(argc == 3) {
		for(it = mp.begin();it != mp.end();it++) {
			cout << it->first << '\n';
			for(int i = 0;i < it->second.size();i++) {
				cout << it->second[i].first << '\t' << it->second[i].second << '\n';
			}
		}
	}
	if(argc == 4) {
		for(it = mp.begin();it != mp.end();it++) {
			if(it->first == stdName) {
				cout << it->first << '\n';
				for(int i = 0;i < it->second.size();i++) {
					cout << it->second[i].first << '\t' << it->second[i].second << '\n';
				}
			}
		}
	}

    return 0;
}
