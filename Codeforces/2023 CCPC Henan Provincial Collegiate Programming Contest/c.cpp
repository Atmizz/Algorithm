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
	int n = (int) str.size();
	str = ')' + str;
	std :: vector <int> v;
	for(int len = 1; len <= n; ++ len) {
		if(n % len != 0 || n <= len) {
			continue ;
		}
		v.push_back(len);
	}
	for(auto len : v) {
		bool ok = true;
		// deb(len);
		for(int i = 1; i < n / len; ++ i) {
			for(int j = (i - 1) * len + 1; j <= i * len; ++ j) {
				if(str[j] != str[j+len]) {
					ok = false;
					break;
				}
			}
			if(!ok) {
				break;
			}
		}
		if(ok) {
			std :: cout << "No";
			return ;
		}
	}
	std :: cout << "Yes\n";
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}