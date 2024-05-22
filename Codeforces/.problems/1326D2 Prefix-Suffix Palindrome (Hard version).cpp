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
const int N = 3e6 + 20;
int sol(const std :: string &s) {
	std :: string exp_s = "#";
	int n = s.size() - 1;
	// deb(n);
	for(int i = 1; i <= n; ++ i) {
		exp_s += s[i];
		exp_s += '#';
	}
	// deb(exp_s.size());
	// std :: cout << exp_s << '\n';
	std :: vector <int> radiuses(exp_s.size());
	int right_radius = -1, right_center = -1, ans = 0;
	for(int i = 0; i < exp_s.size(); ++ i) {
		int radius = i < right_radius ? std :: min(radiuses[right_center*2-i], right_radius - i) : 1;
		while(i + radius < exp_s.size() && i - radius > -1) {
			if(exp_s[i+radius] == exp_s[i-radius]) {
				radius ++;
			} else {
				break;
			}
		}
		radiuses[i] = radius;
		if(i + radius > right_radius) {
			right_radius = i + radius;
			right_center = i;
		}
		if(i == radius - 1) {
			ans = i;
		}
	}
	return ans;
}
void solve() {
	std :: string str;
	std :: cin >> str;
	str = ')' + str;
	int pos = 1, n = str.size() - 1;
	while(pos <= n && str[pos] == str[n-pos+1]) {
		pos ++;
	}
	if(pos == n + 1) {
		for(int i = 1; i <= n; ++ i) {
			std :: cout << str[i];
		}
		std :: cout << '\n';
		return ;
	}
	std :: string res = ")";
	for(int i = pos; i <= n - pos + 1; ++ i) {
		res += str[i];
	}
	int l = sol(res);
	std :: reverse(res.begin() + 1, res.end());
	int r = sol(res);
	std :: reverse(res.begin() + 1, res.end());
	if(l < r) {
		std :: reverse(res.begin() + 1, res.end());
		l = r;
	}
	for(int i = 1; i < pos; ++ i) {
		std :: cout << str[i];
	}
	for(int i = 1; i <= l; ++ i) {
		std :: cout << res[i];
	}
	for(int i = pos - 1; i >= 1; -- i) {
		std :: cout << str[i];
	}
	std :: cout << '\n';
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