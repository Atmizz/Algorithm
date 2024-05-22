#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;

const int N = 1e9 + 20;
const int INF = 0x3f3f3f3f;
const i64 Mod = 998244353;

i64 Pow(i64 x, i64 y) {
	i64 sum = 1ll;
	while(y) {
		if(y & 1ll) sum = sum * x % Mod;
		x = x * x % Mod; y >>= 1ll;
	} return sum % Mod;
}

void solve() {
	i64 n;
	std :: cin >> n;
	std :: cout << (Pow(2, n-1) - 1 + Mod) % Mod << '\n';
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T;
	while(T --) solve();
	return 0;
}