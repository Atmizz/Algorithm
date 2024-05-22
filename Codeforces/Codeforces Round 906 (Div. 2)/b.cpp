#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 110;
void solve() {
	std :: string s, t;
	int n, m; std :: cin >> n >> m;
	std :: cin >> s >> t;
	int flag1 = 0, flag0 = 0;
	for(int i = 0; i < n - 1; ++ i)
		if(s[i] == s[i+1]) {
			if(s[i] == '0') flag0 ++;
			else flag1 ++;
		}
	if(flag0 == 0 && flag1 == 0) {
		std :: cout << "Yes\n";
		return ;
	}
	if(flag0 > 0 && flag1 > 0) {
		std :: cout << "No\n";
		return ;
	}
	if(flag0 > 0) {
		flag0 = 0; flag1 = 0;
		for(int i = 0; i < m - 1; ++ i)
		if(t[i] == t[i+1]) {
			std :: cout << "No\n";
			return ;
		}
		if(t[0] == '1' && t[m-1] == '1') {
			std :: cout << "Yes\n";
			return ;
		}
		std :: cout << "No\n";
		return ;
	}
	if(flag1 > 0) {
		flag0 = 0; flag1 = 0;
		for(int i = 0; i < m - 1; ++ i)
		if(t[i] == t[i+1]) {
			std :: cout << "No\n";
			return ;
		}
		if(t[0] == '0' && t[m-1] == '0') {
			std :: cout << "Yes\n";
			return ;
		}
		std :: cout << "No\n";
		return ;
	}
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