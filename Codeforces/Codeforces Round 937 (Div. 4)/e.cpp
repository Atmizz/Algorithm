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
int t = 0, T;
void solve() {
	int n;
	std :: cin >> n;
	std :: string str;
	std :: cin >> str;
	// t ++;
	// if(t >= 83) {
	// 	std :: cout << n << '\n' << str << '\n';
	// 	return ;
	// }
	std :: vector <int> v;
	v.push_back(0);
	for(int i = 1; i <= sqrt(n); ++ i) {
		if(n % i == 0) {
			v.push_back(i);
			if(i * i != n) {
				v.push_back(n/i);
			}
		}
	}
	
	auto check = [&](int len) {
		int cnt = 0, minn = INF;
		std :: string res = std :: string(str, 0, len);
		std :: string s = "";
		for(int i = 1; i <= n / len; ++ i) {
			s += res;
		}
			// deb(res);
			// deb(s);
			// deb(cnt);
		for(int i = 0; i < n; ++ i) {
			cnt += str[i] != s[i];
		}
		minn = std :: min(minn, cnt);
		if(len * 2 <= n) {
			res.clear();
			for(int i = len; i < len * 2; ++ i) {
				res += str[i];
			}
			s = ""; cnt = 0;
			for(int i = 1; i <= n / len; ++ i) {
				s += res;
			}
			for(int i = 0; i < n; ++ i) {
				cnt += str[i] != s[i];
			}
			// deb(res);
			// deb(s);
			// deb(cnt);
			minn = std :: min(minn, cnt);
		}
		// deb(cnt)
		return minn <= 1;
	};
	std :: sort(v.begin(), v.end());
	for(int i = 1; i <= v.size() - 1; ++ i) {
		// deb(v[i]);
		if(check(v[i])) {
			std :: cout << v[i] << '\n';
			return ;
		}
	}
	std :: cout << n << '\n';
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	// int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}