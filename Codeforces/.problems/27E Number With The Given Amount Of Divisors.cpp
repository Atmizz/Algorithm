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
const int N = 1e7 + 20;
std :: vector <i64> prime;
int isNotPrime[N];
void solve() {
	i64 sum = 1;
	for(int i = 2; i < N; ++ i) {
		if(!isNotPrime[i]) {
			prime.pb(i);
			sum *= i;
			if(sum >= 1e18) {
				break;
			}
		}
		for(int j = 0; j < sz(prime) && i * j < N; ++ j) {
			isNotPrime[prime[j]*i] = 1;
			if(i % prime[j] == 0) {
				break;
			}
		}
	}
	int n;
	std :: cin >> n;
	ull ans = LLINF;
	auto dfs = [&](auto dfs, ull tar, int pos, int res, int up) -> void {
		if(tar > ans || pos >= 16 || res > n) {
			return ;
		}
		if(res == n) {
			ans = min(ans, tar);
			return ;
		}
		for(int i = 1; i <= up; ++ i) {
			dfs(dfs, tar = tar * prime[pos], pos + 1, res * (i + 1), i);
		}
	};
	dfs(dfs, 1LL, 0, 1, 64);
	std :: cout << ans;
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