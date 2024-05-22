#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 110;
int n, m, a[N][N];
std :: vector <int> dvd;
int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> a[i][j];
		}
	}
	dvd.clear();
	int Gcd = gcd(a[1][1], a[n][m]);
	for(int i = 1; i <= sqrt(Gcd); ++ i) {
		if(Gcd % i) {
			continue;
		}
		dvd.push_back(i);
		if(i * i != Gcd) {
			dvd.push_back(Gcd / i);
		}
	}
	std :: sort(dvd.begin(), dvd.end(), [&](int a, int b) {
		return a > b;
	});
	std :: vector dp(n+1, std :: vector <int> (m+1));
	auto check = [&](int z) {
		for(int i = 1; i <= n; ++ i) {
			for(int j = 1; j <= m; ++ j) {
				dp[i][j] = 0;
			}
		}
		dp[1][1] = 1;
		for(int i = 1; i <= n; ++ i) {
			for(int j = 1; j <= m; ++ j) {
				if(a[i][j] % z == 0) {
					dp[i][j] |= dp[i-1][j] | dp[i][j-1];
				}
			}
		}
		return dp[n][m];
	};
	for(auto x : dvd) {
		if(check(x)) {
			std :: cout << x << '\n';
			return ;
		}
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