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
const int N = 1e6 + 20;
int n, a, b, fac[N], invFac[N];
int quickMi(int a, int b) {
	int sum = 1;
	while(b) {
		if(b & 1) {
			sum = 1LL * sum * a % Mod;
		}
		b >>= 1; a = 1LL * a * a % Mod;
	}
	return sum;
}
void solve() {
	std :: cin >> a >> b >> n;
	fac[0] = 1;
	for(int i = 1; i <= n; ++ i) {
		fac[i] = 1LL * fac[i-1] * i % Mod;
	}
	invFac[n] = quickMi(fac[n], Mod - 2);
	for(int i = n - 1; i >= 0; -- i) {
		invFac[i] = 1LL * invFac[i+1] * (i + 1) % Mod;
	}
	auto check = [&](int x) -> bool {
		while(x) {
			int y = x % 10;
			if(y != a && y != b) {
				return false;
			}
			x /= 10;
		}
		return true;
	};
	auto C = [&](int a, int b) -> int {
		return 1LL * fac[a] * invFac[b] % Mod * invFac[a-b] % Mod;
	};
	int ans = 0;
	for(int i = 0; i <= n; ++ i) {
		if(check(i * a + b * (n - i))) {
			ans = (ans + C(n, i)) % Mod;
		}
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