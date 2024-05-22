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
const int Mod = 998244353;
const int N = 2e6 + 20;
const int M = 2e6;
int quickPow(int a,int b) {
	int sum = 1;
	while(b) {
		if(b & 1) {
			sum = 1LL * sum * a % Mod;
		}
		b >>= 1; a = 1LL * a * a % Mod;
	}
	return sum;
}
int fac[N], invFac[N];
void prepare() {
	fac[0] = 1;
	for(int i = 1; i <= M; ++ i) {
		fac[i] = 1LL * fac[i-1] * i % Mod;
	}
	invFac[M] = quickPow(fac[M], Mod - 2);
	for(int i = M - 1; i >= 0; -- i) {
		invFac[i] = 1LL * invFac[i+1] * (i + 1) % Mod;
	}
}
int C(int a, int b) {
	return 1LL * fac[a] * invFac[b] % Mod * invFac[a-b] % Mod;
}
void solve() {
	int c[5];
	for(int i = 1; i <= 4; ++ i) {
		std :: cin >> c[i];
	}
	if(std :: abs(c[1] - c[2]) > 1) {
		std :: cout << 0 << '\n';
		return ;
	}
	int ans = 0;
	if(c[1] == c[2]) {
		if(c[1] == 0) {
			std :: cout << ((c[3] && c[4]) ? 0 : 1);
			std :: cout << '\n';
			return ;
		}
		ans = (ans + 1LL * C(c[1]+c[3], c[1]) % Mod * C(c[2]+c[4]-1, c[2]-1) % Mod) % Mod;
		ans = (ans + 1LL * C(c[1]+c[3]-1, c[1]-1) % Mod * C(c[2]+c[4], c[2]) % Mod) % Mod;
	} else {
		int a = std :: max(c[1], c[2]);
		ans = (ans + 1LL * C(a+c[3]-1, a-1) % Mod * C(a+c[4]-1, a-1) % Mod) % Mod;
	}
	std :: cout << ans % Mod << '\n';
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	prepare();
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}