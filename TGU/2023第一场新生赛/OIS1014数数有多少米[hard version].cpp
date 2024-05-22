#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e7 + 20;
i64 sum[N<<1], a[N<<1], n, k, Prime[N>>2], cnt;
bool isNotPrime[N<<1];
void oula() {
	for(int i = 2; i < N << 1; ++ i) {
		if(!isNotPrime[i]) Prime[++cnt] = i;
		for(int j = 1; j <= cnt && i * Prime[j] < N << 1; ++ j) {
			isNotPrime[i*Prime[j]] = 1;
			if(i % Prime[j] == 0) break;
		}
	}
}
i64 quickMi(i64 a, i64 b) {
	i64 res = 1;
	while(b) {
		if(b & 1) res = res * a % Mod;
		a = a * a % Mod; b >>= 1;
	} return res % Mod;
}
void solve() {
	std :: cin >> n >> k;
	for(int i = 1; i <= n << 1; ++ i)
		a[i] = 1;
	for(int i = 1; i <= cnt && Prime[i] <= n << 1; ++ i)
		a[Prime[i]] = quickMi(Prime[i], k) % Mod;
	for(int i = 2; i <= n << 1; ++ i)
		for(int j = 1; j <= cnt && i * Prime[j] <= n << 1; ++ j) {
			// deb(i*Prime[j]); deb(i);
			a[i*Prime[j]] = a[Prime[j]] * a[i] % Mod;
			if(i % Prime[j] == 0) break;
		}
	for(int i = 1; i <= n << 1; ++ i)
		sum[i] = (sum[i-1] + a[i]) % Mod;
	i64 ans = 0;
	for(int i = 1; i <= n; ++ i)
		ans = (ans + sum[i+n] - sum[i] + Mod) % Mod;
	std :: cout << ans << endl;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	oula();
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}