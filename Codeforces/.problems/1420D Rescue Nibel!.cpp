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
const int Mod = 998244353;
const int N = 3e5 + 20;
i64 fac[N], invFac[N];
i64 quickPower(i64 a, i64 b) {
	i64 res = 1;
	while(b) {
		if(b & 1LL) {
			res = res * a % Mod;
		}
		b >>= 1LL; a = a * a % Mod;
	}
	return res;
}
int b[N<<1], cnt, sum[N<<1];
void solve() {
	int n, k;
	std :: cin >> n >> k;
	fac[0] = invFac[0] = 1;
	for(int i = 1; i <= n; ++ i) {
		fac[i] = fac[i-1] * i % Mod;
	}
	invFac[n] = quickPower(fac[n], Mod - 2);
	for(int i = n - 1; i >= 1; -- i) {
		invFac[i] = invFac[i+1] * (i + 1) % Mod;
	}
	std :: vector <PII> a(n);
	for(auto &[l, r] : a) {
		std :: cin >> l >> r;
		b[++cnt] = l;
		b[++cnt] = r;
	}
	std :: sort(b + 1, b + 1 + cnt);
	int m = std :: unique(b + 1, b + 1 + cnt) - b - 1;
	std :: sort(a.begin(), a.end());
	for(auto &[l, r] : a) {
		l = std :: lower_bound(b + 1, b + 1 + m, l) - b;
		r = std :: lower_bound(b + 1, b + 1 + m, r) - b;
		// std :: cout << l << ' ' << r << nl;
	}
	std :: cout << nl;
	auto lowbit = [&](int x) -> int {
		return x & -x;
	};
	auto add = [&](int x) -> void {
		for(; x <= m; x += lowbit(x)) {
			sum[x] ++;
		}
	};
	auto query = [&](int x) -> int {
		int s = 0;
		for(; x; x -= lowbit(x)) {
			s += sum[x];
		}
		return s;
	};
	auto C = [&](int a, int b) -> i64 {
		return fac[a] * invFac[b] % Mod * invFac[a-b] % Mod;
	};
	i64 ans = 0;
	for(int i = 0; i < n; ++ i) {
		auto &[l, r] = a[i];
		int c = query(m) - query(l - 1);
		// std :: cout << i << ' ' << c << nl;
		if(k - 1 <= c) {
			ans = (ans + C(c, k - 1)) % Mod;
		}
		add(r);
	}
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