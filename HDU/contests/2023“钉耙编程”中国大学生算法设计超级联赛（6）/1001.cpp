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
const i64 Mod = 998244353;

i64 qmi(i64 a, i64 b) {
	i64 sum = 1;
	a %= Mod; b %= Mod;
	while(b) {
		if(b & 1) sum = sum * a % Mod;
		a = a * a % Mod; b >>= 1;
	} return sum % Mod;
}

void solve() {
	i64 n, m, k;
	std :: cin >> n >> m >> k;
	if(k * 3 < n * 2) {
		std :: cout << qmi(m, n - k) % Mod << endl;
	} else if(k * 3 == n * 2) {
		std :: cout << qmi(m, n / 3) % Mod << endl;
	}else if(n == k) {
		std :: cout << qmi(m, n) % Mod << endl;
	}else {
		std :: cout << m % Mod << endl;
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