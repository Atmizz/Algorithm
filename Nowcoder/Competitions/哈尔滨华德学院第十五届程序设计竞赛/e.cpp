#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define mk std :: make_pair
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << '\n';
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
typedef unsigned long long ull;
template <class T>
T max(T a, T b) {
	return a > b ? a : b;
}
template <class T>
T min(T a, T b) {
	return a < b ? a : b;
}
template <class T>
T abs(T a) {
	return a < 0 ? -a : a;
}
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
void solve() {
	std :: string s, mom = "";
	getline(std :: cin, s);
	std :: vector <int> vis(26);
	auto chg = [&](char x) -> char {
		if(x >= 'A' && x <= 'Z') {
			return x;
		}
		return char(x - 'a' + 'A');
	};
	for(auto &x : s) {
		int y = -1;
		if(x >= 'a' && x <= 'z') {
			y = x - 'a';
		}
		if(x >= 'A' && x <= 'Z') {
			y = x - 'A';
		}
		if(y != -1 && !vis[y]) {
			mom += chg(x);
			vis[y] = 1;
		}
	}
	for(int i = 0; i < 26; ++ i) {
		if(!vis[i]) {
			mom += char(i + 'A');
		}
	}
	auto Go = [&](char x) -> char {
		if(x >= 'a' && x <= 'z') {
			return mom[x-'a'];
		}
		return x;
	};
	auto Back = [&](char x) -> char {
		if(x >= 'A' && x <= 'Z') {
			for(int i = 0; i < 26; ++ i) {
				if(mom[i] == x) {
					return char(i + 'a');
				}
			}
		}
		return x;
	};
	while(1) {
		std :: string opt, str;
		getline(std :: cin, opt);
		if(opt == "END") {
			std :: cout << "Thanks for using goodbye!";
			break;
		}
		getline(std :: cin, str);
		if(opt == "encryption") {
			for(auto &x : str) {
				x = Go(x);
				// x = 'A';
			}
		} else {
			for(auto &x : str) {
				x = Back(x);
				// x = 'a';
			}
		}
		std :: cout << str << nl;
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	//std :: cin >> _; 
	while(_ --) solve();
	return 0;
}