#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
std :: mt19937 rd(114514);
void solve() {
	std :: string str;
	std :: cin >> str;
	int len = (int) str.size();
	std :: vector <int> v;
	int l = len / 2, r = len / 2;
	for(int i = 0; i < len; ++ i) {
		if(str[i] == '(') {
			l --;
		} else if(str[i] == ')') {
			r --;
		} else {
			v.push_back(i);
		}
	}
	for(int i = 0; i < (int) v.size(); ++ i) {
		if(i < l) {
			str[v[i]] = '(';
		} else {
			str[v[i]] = ')';
		}
	}
	bool ok = true;
	auto check = [&](std :: string s) {
		int res = 0;
		for(auto x : s) {
			if(x == '(') {
				res ++;
			} else {
				res --;
			}
			// deb(res);
			if(res < 0) {
				return false;
			}
		}
		return true;
	};
	if(l > 0 && r > 0) {
		std :: swap(str[v[l-1]], str[v[l]]);
		if(check(str)) {
			ok = false;
		}
	}
	std :: cout << (ok ? "YES\n" : "NO\n");
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}