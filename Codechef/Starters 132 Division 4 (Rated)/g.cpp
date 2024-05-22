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
	std :: vector <int> fre(n+1);
	for(int i = 0; i < n; ++ i) {
		std :: cin >> fre[i];
	}
	std :: vector <int> ans(n+1);
	std :: vector <int> dp(n+1);
	ans[0] = fre[0];
	auto dfs = [&](auto dfs, int x, int step) -> int {
		if(fre[x] > 1) {
			fre[x] --;
			return step;
		}
		if(x == 0) {
			return -1;
		}
		return dfs(dfs, x / 2, step + 1);
	};
	int sum = 0;
	for(int i = 1; i <= n; ++ i) {
		if(ans[i-1] == -1) {
			ans[i] = -1;
			continue ;
		}
		if(fre[i-1] == 0) {
			int res = dfs(dfs, i-1, 0);
			if(res == -1) {
				ans[i] = -1;
			} else {
				sum += res;
			}
		}
		if(ans[i] != -1) {
			ans[i] = sum + fre[i];
		}
	}
	for(int i = 0; i <= n; ++ i) {
		std :: cout << ans[i] << " \n"[i == n];
	}
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