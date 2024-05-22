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
const int N = 2e5 + 20;
int n, m1, m2, a[N], b[N];
i64 fac[N], inFac[N];
i64 qm(i64 a, i64 b) {
	i64 f = 1;
	while(b) {
		if(b & 1LL) {
			f = f * a % Mod;
		}
		b >>= 1LL; a = a * a % Mod;
	}
	return f % Mod;
}
i64 A(i64 a, i64 b) {
	return fac[a] * inFac[a-b] % Mod;
}
i64 C(i64 a, i64 b) {
	return fac[a] * inFac[b] % Mod * inFac[a-b] % Mod;
}
void solve() {
	std :: cin >> n >> m1 >> m2;
	for(int i = 1; i <= m1; ++ i) {
		std :: cin >> a[i];
	}
	for(int i = 1; i <= m2; ++ i) {
		std :: cin >> b[i];
	}
	if(a[m1] != b[1] || a[1] != 1 || b[m2] != n) {
		std :: cout << 0 << '\n';
		return ;
	}
	i64 ans = 1;
	for(int i = 2; i <= m1; ++ i) {
		if(a[i] - a[i-1] != 1) {
			ans = ans * A(a[i] - 2, a[i] - a[i-1] - 1) % Mod;
			// DEB
			// std :: cout << a[i] - 2 << ' ' << a[i] - a[i-1] - 1 << '\n';
		}
	}
	for(int i = m2 - 1; i >= 1; -- i) {
		if(b[i+1] - b[i] != 1) {
			ans = ans * A(n-b[i]-1, b[i+1] - b[i] - 1) % Mod;
			// DEB
			// std :: cout << n - b[i] - 1 << ' ' << b[i+1] - b[i] - 1 << '\n';
		}
	}
	ans = ans * C(n - 1, a[m1] - 1) % Mod;
	std :: cout << ans % Mod << '\n';
}
void pre() {
	fac[0] = 1;
	int M = N - 20;
	for(int i = 1; i <= M; ++ i) {
		fac[i] = fac[i-1] * i % Mod;
	}
	inFac[M] = qm(fac[M], Mod - 2);
	for(int i = M - 1; i >= 0; -- i) {
		inFac[i] = inFac[i+1] * (i + 1) % Mod;
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1; pre();
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}