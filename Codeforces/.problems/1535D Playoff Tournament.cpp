#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls u << 1
#define rs u << 1 | 1
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
	int k;
	std :: cin >> k;
	std :: string s;
	std :: cin >> s;
	int n = sz(s);
	std :: reverse(s.begin(), s.end());
	s = '0' + s;
	std :: vector <int> sum(n+1);
	auto dfs1 = [&](auto dfs1, int u) -> void {
		if(u >= (1 << k - 1)) {
			sum[u] = 1 + (s[u] == '?');
			return ;
		}
		dfs1(dfs1, ls);
		dfs1(dfs1, rs);
		if(s[u] == '?') {
			sum[u] = sum[ls] + sum[rs];
		} else if(s[u] == '0') {
			sum[u] = sum[rs];
		} else {
			sum[u] = sum[ls];
		}
	};第二题最长公共子序列问题
	auto dfs2 = [&](auto dfs2, int u, int x, char ch) -> void {
		if(u == x) {
			s[u] = ch;
		}
		if(u >= (1 << k - 1)) {
			sum[u] = 1 + (s[u] == '?');
		} else {
			if(s[u] == '?') {
				sum[u] = sum[ls] + sum[rs];
			} else if(s[u] == '0') {
				sum[u] = sum[rs];
			} else {
				sum[u] = sum[ls];
			}
		}
		if(u == 1) {
			return ;
		}
		dfs2(dfs2, u / 2, x, ch);
	};
	dfs1(dfs1, 1);
	int q;
	std :: cin >> q;
	while(q --) {
		int x;
		char ch;
		std :: cin >> x >> ch;
		x = n - x + 1;
		dfs2(dfs2, x, x, ch);
		std :: cout << sum[1] << nl;
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