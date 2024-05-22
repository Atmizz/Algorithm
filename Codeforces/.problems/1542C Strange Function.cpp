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
const int Mod = 1e9 + 7;
const i64 N = 1e16;

i64 gcd(i64 a, i64 b) {
	return b ? gcd(b, a % b) : a;
}

void solve() {
	i64 n1, n2, n;
	std :: cin >> n;
	i64 lcm[50], ans = 0;
	lcm[1] = 1;
	for(i64 i = 2; ; ++ i) {
		lcm[i] = lcm[i-1] / gcd(lcm[i-1], i) * i;
		ans = (ans + i * (n / lcm[i-1] - n / lcm[i]) % Mod) % Mod;
		if(lcm[i] > n) break;
	}
	std :: cout << ans << endl;
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