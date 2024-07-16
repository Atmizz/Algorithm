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
	int n;
	std :: cin >> n;
	std :: string s;
	std :: cin >> s;
	s = '0' + s;
	int ans = INF;
	for(int i = 1; i < n; ++ i) {
		int now = (s[i] - 48) * 10 + s[i+1] - 48;
		int tmp = now;
		if(now == 0) {
			std :: cout << 0 << nl;
			return ;
		}
 		for(int j = 1; j <= n; ++ j) {
			if(j == i || j == i + 1) {
				continue ;
			}
			if(s[j] == '0') {
				std :: cout << 0 << nl;
				return ;
			}
			if(s[j] != '1') {
				now += s[j] - 48;
			}
		}
		if(now > tmp && tmp == 1) {
			now --;
		}
		ans = min(ans, now);
	}
	std :: cout << ans << nl;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}