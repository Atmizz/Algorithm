#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int N = 1e6+20;
const int p = 998244353;
i64 qmi(i64 a, i64 b) {
	i64 sum = 1ll;
	while(b) {
		if(b & 1) sum = sum * a % p;
		a = a * a % p; b >>= 1;
	} return sum % p;
}
i64 f[N], W[N], L[N], Lu[N], fac[N];
void solve() {
	i64 n, m, a, b, ans = 0;
	scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
	
	f[1] = 1ll;
	for(i64 i = 2; i <= n; ++ i)
		f[i] = qmi(i, m) % p, f[i] = (f[i-1] + f[i]) % p;

	i64 win = a * qmi(b, p - 2) % p, lose = (b - a) * qmi(b, p - 2) % p;
	W[0] = L[0] = 1;
	for(int i = 1; i <= n; ++ i)
		W[i] = W[i-1] * win % p, L[i] = L[i-1] * lose % p;

	// 组合数
	Lu[1] = n;
	for(int i = 2, j = n - 1; i <= n; ++ i, -- j)
		Lu[i] = Lu[i-1] * j % p * fac[i] % p;
	
	for(i64 i = 1; i <= n; ++ i)
	 	ans = (ans + ((Lu[i] * W[i] % p) * L[n-i] % p) * f[i] % p) % p;
	printf("%lld\n", ans % p);
}

int main() {
	//freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	for(i64 i = 1; i <= N - 20; ++ i)
		fac[i] = qmi(i, p - 2) % p;
	int T = 1;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}