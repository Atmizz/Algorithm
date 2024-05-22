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
const i64 Mod = 1e9 + 7;
const int N = 1e5 + 20;
i64 Ma[N], Mb[N], p[N], n, ma, mb;
void solve() {
	std :: cin >> n;
	std :: cin >> ma;
	for(int i = 1; i <= ma; ++ i) {
		std :: cin >> Ma[i];
	}
	std :: cin >> mb;
	for(int j = 1; j <= mb; ++ j) {
		std :: cin >> Mb[j];
	}
	for(int j = 1; j <= std :: max(ma, mb); ++ j) {
		p[j] = std :: max(std :: max(Ma[j], Mb[j]) + 1, 2LL);
	}
	for(int i = std :: max(ma, mb) - 1; i >= 1; -- i) {
		p[i] = p[i] * p[i+1] % Mod;
	}
	i64 ans = 0;
	p[std::max(ma,mb)+1] = 1;
	for(int i = 1; i <= std :: max(ma, mb); ++ i) {
		ans = (ans + (Ma[i] - Mb[i]) * p[i+1] % Mod + Mod) % Mod;
	}
	std :: cout << (ans + Mod) % Mod << '\n';
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