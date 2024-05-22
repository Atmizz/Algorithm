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
	int n, q;
	std :: cin >> n >> q;
	std :: string s;
	std :: cin >> s;
	s = '0' + s;
	std :: string res = "red";
	std :: vector sum(n+1, std :: vector <int> (3));
	for(int i = 1; i <= n; ++ i) {
		for(int j = 0; j < 3; ++ j) {
			sum[i][j] = sum[i-1][j] + (res[j] != s[i]);
		}
	}
	// for(int i = 1; i <= n; ++ i) {
	// 	std :: cout << sum[i][0] << ' ' << sum[i][1] << ' ' << sum[i][2] << '\n';
	// }
	while(q --) {
		int l, r;
		std :: cin >> l >> r;
		int len = r - l + 1;
		if(len < 3) {
			std :: cout << 0 << nl;
			continue ;
		}
		int ans = 0;
		if(len % 3 == 0) {
			len /= 3;
			int pos = l - 1;
			for(int i = 0; i < 3; ++ i) {
				pos += len;
				// std :: cout << pos - len + 1 << ' ' << pos << nl;
				ans += sum[pos][i] - sum[pos-len][i];
			}
		} else if(len % 3 == 1) {
			len /= 3;
			ans = INF;
			for(int i = 0; i < 3; ++ i) {
				int res = 0, pos = l - 1;
				for(int j = 0; j < 3; ++ j) {
					pos += len + (i == j);
					// std :: cout << pos - len - (i == j) + 1 << ' ' << pos << nl;
					res += sum[pos][j] - sum[pos-len-(i==j)][j];
				}
				// deb(res);
				ans = min(ans, res);
			}
		} else {
			len /= 3;
			ans = INF;
			len ++;
			for(int i = 0; i < 3; ++ i) {
				int res = 0, pos = l - 1;
				for(int j = 0; j < 3; ++ j) {
					pos += len - (i == j);
					res += sum[pos][j] - sum[pos-len+(i==j)][j];
				}
				ans = min(ans, res);
			}
		}
		std :: cout << ans << nl;
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