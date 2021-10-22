#include <bits/stdc++.h>

using namespace std;

namespace Core {
	string s, ss, stdName;
	map<string, vector<pair<string, int > > > mp;
	map<string, int> __hash;
	int x = 0, op = 0;
	static int hash_cnt;
	char add11[111]{}, add22[111]{};
	string add1 = "C:\\Users\\jkxy\\Desktop\\";
	string add2 = "C:\\Users\\jkxy\\Desktop\\";

	class City {
		public:
			string city;
			int city_num;
			City() {}
			City(string __city, int __city_num) : city(__city), city_num(__city_num) {};
		public:
			friend bool operator < (City A, City B) {
				if(A.city_num == B.city_num) return A.city > B.city;
				return A.city_num > B.city_num;
			}
			void show() {
				cout << city << '\t' << city_num << '\n';
			}
	};

	class Province {
		public:
			string province;
			vector<City> city_of_province;
			int prov_num;
		public:
			friend bool operator<(Province A, Province B) {
				if(A.prov_num == B.prov_num) return A.province > B.province;
				return A.prov_num > B.prov_num;
			}

			int getTot() {
				int ret = 0;
				for(City i : city_of_province) ret += i.city_num;
				return ret;
			}

			void show() {
				cout << province << '\t' << prov_num << '\n';
			}
	};

	class Country {
		public:
			vector<Province> prov_of_country;	
		public:
			Country() {}

			void merge() {
				for(auto i : mp) {
					Province tmpProv;
					int hash_value = __hash[i.first];
					tmpProv.province = i.first;
					for(auto it : i.second) tmpProv.city_of_province.push_back(City(it.first, it.second));
					tmpProv.prov_num = tmpProv.getTot();
					this->prov_of_country.push_back(tmpProv);
				}
			}

			void showAll() {
				sort(prov_of_country.begin(), prov_of_country.end());
				for(auto i : prov_of_country) {
					i.show();
					sort(i.city_of_province.begin(), i.city_of_province.end());
					for(auto it : i.city_of_province) it.show();
					cout << '\n';
				}
			}

			void showPartial(char* loc) {
				string LOC = "";
				for(int i = 0;i < strlen(loc);i++) LOC += loc[i];
				for(Province now : this -> prov_of_country) {
					if(now.province == LOC) {
						now.show();
						for(City C : now.city_of_province) {
							C.show();
						}
					}
				}
			};

			void initialize() {
				while(cin >> s >> ss >> x) {
					if(ss == "待明确地区") continue;
					mp[s].push_back(pair<string, int>(ss, x));
				}
				for(auto i : mp) __hash[i.first] = hash_cnt++;
			}
	};

	void init(int argc, char* argv[]) {
		if(argc == 1) {
			char default1[] = "yq_in.txt";
			char default2[] = "yq_out.txt";
			for(int i = 0;i < strlen(default1);i++) add1 += default1[i];
			for(int i = 0;i < strlen(default2);i++) add2 += default2[i];
			for(int i = 0;i < add1.size();i++)      add11[i] = add1[i];
			for(int i = 0;i < add2.size();i++)      add22[i] = add2[i];
			op = 1;
		}
		else {
			bool file_ = 0;
			for(int i = 0;i < strlen(argv[2]);i++) if(argv[2][i] == '.') file_ = true;
			if(file_) {
				for(int i = 0;i < strlen(argv[1]);i++) add1 += argv[1][i];
				for(int i = 0;i < strlen(argv[2]);i++) add2 += argv[2][i];
				for(int i = 0;i < add1.size();i++)     add11[i] = add1[i];
				for(int i = 0;i < add2.size();i++)     add22[i] = add2[i];
				op = 2;
			}
			else {
				char *default1 = argv[1];
				char default2[] = "yq_out.txt";
				for(int i = 0;i < strlen(default1);i++) add1 += default1[i];
				for(int i = 0;i < strlen(default2);i++) add2 += default2[i];
				for(int i = 0;i < add1.size();i++)      add11[i] = add1[i];
				for(int i = 0;i < add2.size();i++)      add22[i] = add2[i];
				op = 3;
			}
		}
	}
};

using namespace Core;

int main(int argc, char *argv[]) {
	init(argc, argv);

	freopen(add11, "r", stdin);	
	freopen(add22, "w", stdout);

	Country country;
	country.initialize();
	country.merge();

	if(op == 1) country.showAll();
	if(op == 2) country.showAll();
	if(op == 3) country.showPartial(argv[2]);

	return 0;
}
