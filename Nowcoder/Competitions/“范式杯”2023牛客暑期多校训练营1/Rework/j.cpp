#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
typedef long long ll;

const int Mod = 998244353;

ll Pow(ll a, int b) {
	ll sum = 1ll;
	while(b) {
		if(b & 1) sum = sum * a % Mod;
		a = a * a % Mod; b >>= 1;
	} return sum % Mod;
}

void solve() {
	int n, m;
	ll ans = 1, inv = (Pow(2, Mod-2) + Mod) % Mod;
	std :: cin >> n >> m;
	for(int i = 1; i <= m; ) { // 1, 2, ..., 2^n-1 =2^n - 1
		int lg = std :: __lg(n+i); // lg 表示已经赢得了(i-1)元，最多输的次数
		ll v = (1ll - Pow(inv, lg) + Mod) % Mod; // 赢一元的概率
		int j = std :: min(m, (1 << (lg + 1)) - n - 1); // 
		ans *= Pow(v, j - i + 1);
		ans = (ans + Mod) % Mod;
		i = j + 1;
	}
	std :: cout << (ans + Mod) % Mod;
}
 
int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T;
	while(T --) solve();
	return 0;
}