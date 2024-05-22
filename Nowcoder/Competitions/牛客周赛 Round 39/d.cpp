#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 4e6 + 20;
int n, p, a[N], f[N], mp[N];
void solve() {
	std :: cin >> n >> p;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		mp[a[i]%p] ++;
	}
	if(mp[0]) {
		std :: cout << 1 << '\n';
		return ;
	}
	std :: fill(f + 1, f + 1 + p * (p - 1), INF);
	for(int i = 1; i < p; ++ i) {
		if(!mp[i]) {
			continue;
		}
		for(int j = i; j <= p * (p - 1); ++ j) {
			f[j] = std :: min(f[j], f[j-i] + 1);
		}
	}
	int ans = INF;
	for(int i = p; i <= p * (p - 1); i += p) {
		ans = std :: min(ans, f[i]);
	}
	std :: cout << ans;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}