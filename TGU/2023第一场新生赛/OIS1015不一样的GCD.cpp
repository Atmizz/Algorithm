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
const int N = 0;
i64 gcd(i64 a, i64 b) {
	return b ? gcd(b, a % b) : a;
}
i64 quickMi(i64 b) {
	i64 res = 1, a = 2;
	while(b) {
		if(b & 1) res = res * a % Mod;
		a = a * a % Mod; b >>= 1;
	} return res;
}
void solve() {
	i64 i, j;
	std :: cin >> i >> j;
	i64 GCD = gcd(i, j);
	std :: cout << (quickMi(GCD) - 1 + Mod)% Mod << endl;
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