#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;
const int N = 1e5 + 200;

int fact[N];

int quick_mul(int a, int b) {
	int sum = 1;
	while(b) {
		if(b & 1) sum = (i64) sum * a % Mod;
		a = (i64) a * a % Mod; b >>= 1;
	} return sum % Mod;
}

void prepare() {
	fact[0] = 1;
	for(int i = 1; i <= N; ++ i)
		fact[i] = (i64) fact[i-1] * i % Mod;
}

void solve() {
	int n, m;
	std :: cin >> n >> m;
	std :: cout << (i64) fact[n] * quick_mul(fact[m], Mod-2) % Mod * quick_mul(fact[n-m], Mod-2) % Mod << endl;
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	prepare();
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}