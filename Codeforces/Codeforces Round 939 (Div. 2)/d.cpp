#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << endl;
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
std :: vector <PII> v;
void dfs(int l, int r) {
	if(l == r) {
		return ;
	}
	
}
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <int> a(n);
	for(int &x : a) {
		std :: cin >> x;
	}
	std :: vector <int> dp(1 << n);
	for(int _ = 0; _ < 1 << n; ++ _) {
		for(int i = 0; i < n; ++ i) {
			if(!(_ >> i & 1)) {
				dp[_] += a[i];
			}
		}
		for(int i = 0; i < n; ++ i) {
			if(_ >> i & 1) {
				int j = i;
				while(j < n && (_ >> j & 1)) {
					j ++;
				}
				j --;
				int mex = j - i + 1;
				dp[_] += mex * mex;
				// std :: cout << _ << ' ' << i << ' ' << j << ' ' << dp[_] << '\n';
				i = j;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < 1 << n; ++ i) {
		ans = max(ans, dp[i]);
	}
	for(int _ = 0; _ < 1 << n; ++ _) {
		if(ans == dp[_]) {
			for(int i = 0; i < n; ++ i) {
				if(_ >> i & 1) {
					int j = i;
					while(j < n && (_ >> j & 1)) {
						j ++;
					}
					j --;
					for(int k = i; k <= j; ++ k) {
						if(a[k] != 0) {
							v.push_back({k, k});
						}
					}

					for(int k = 1; k <= i + j - 1; ++ k) {

					}
					i = j;
				}
			}
			break;
		}
	}
	std :: cout << ans << ' ' << (int) v.size() << nl;
	for(auto [l, r] : v) {
		std :: cout << l + 1 << ' ' << r + 1 << '\n';
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