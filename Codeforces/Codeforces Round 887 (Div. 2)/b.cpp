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
const int N = 2e5 + 290;
i64 a[N], b[N];

void prepare() {
	a[1] = 1ll; b[2] = 1ll;
	for(int i = 3; i <= 29; ++ i) a[i] = a[i-1] + a[i-2], b[i] = b[i-1] + b[i-2];
}

void solve() {
	i64 n, k, x, y;
	std :: cin >> n >> k;
	if(k >= 29) {
		std :: cout << "0\n";
		return ;
	}
	i64 ans = 0, l = 0, r = n / (a[k] + b[k]);
	// deb(r);
	for(i64 i = l; i <= r; ++ i)
		if((n - a[k] * i) % b[k] == 0 && (n - a[k] * i) > 0) {
			ans ++;
			// std :: cout << "f[1] = " << i << ' ' << "f[2] = " << (n - a[k] * i) / b[k] << endl;
		}
	std :: cout << ans << endl;
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	prepare();
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}