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
const int N = 1e5 + 20;
/*
性质1：ans=变化次数+步数
性质2：对称的字母最少变化次数是相同的
性质3：因为对称的，所以可以只考虑一半。
性质3：本质求最少步数（设为在前半部分）
起初位置：pos
第一个修改位置： p1
1 2 3 4 5 6 7 8 9 10

*/
void solve() {
	int n, p;
	std :: cin >> n >> p;
	if(p > n / 2) {
		p = n - p + 1;
	}
	std :: string str;
	std :: cin >> str;
	str = '0' + str;
	int ans = 0, p1 = 0, p2 = 0;
	for(int i = 1; i <= n / 2; ++ i) {
		if(str[i] == str[n-i+1]) {
			continue;
		} else {
			if(!p1) {
				p1 = i;
			} else {
				p2 = i;
			}
			ans += std :: min(std :: abs(str[i] - str[n-i+1]), 26 - std :: abs(str[i] - str[n-i+1]));
		}
	}
	if(p2 == 0) {
		p2 = p1;
	}
	// deb(p);
	// deb(p1);
	// deb(p2);
	if(p1 == 0 && p2 == 0) {
		ans += 0;
	} else if(p <= p1 || p >= p2) {
		ans += std :: max(std :: abs(p - p1), std :: abs(p - p2));
	} else {
		ans += p2 - p1 + std :: min(std :: abs(p2 - p), std :: abs(p - p1));
	}
	std :: cout << ans;
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