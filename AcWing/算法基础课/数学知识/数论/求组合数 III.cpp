#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

i64 a, b, p;

i64 qmi(i64 a, i64 b) {
	i64 sum = 1ll;
	while(b) {
		if(b & 1) sum = sum * a % p;
		a = a * a % p; b >>= 1;
	} return sum;
}

i64 C(i64 n, i64 m) {
	i64 res = 1ll;
	for(i64 i = 1, j = n; i <= m; ++ i, j --) {
		res = res * j % p;
		res = res * qmi(i, p-2) % p;
	} return res;
}

i64 lucas(i64 a, i64 b) {
	if(a < p && b < p) return C(a, b) % p;
	return C(a % p, b % p) * lucas(a / p, b / p) % p;
}
void solve() {
	
	std :: cin >> a >> b >> p;
	std :: cout << lucas(a, b) << endl;
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