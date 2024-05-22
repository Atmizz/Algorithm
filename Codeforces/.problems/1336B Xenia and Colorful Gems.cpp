#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
int nr, ng, nb;
i64 r[N], g[N], b[N];
i64 get(i64 a, i64 b, i64 c) {
	if(a == INF || b == INF || c == INF) {
		return LLINF;
	}
	if(a == 0 || b == 0 || c == 0) {
		return LLINF;
	}
	return (a - b) * (a - b) + (a - c) * (a - c) + (b - c) * (b - c);
}
void solve() {
	std :: cin >> nr >> ng >> nb;
	for(int i = 1; i <= nr; ++ i) {
		std :: cin >> r[i];
	}
	for(int i = 1; i <= ng; ++ i) {
		std :: cin >> g[i];
	}
	for(int i = 1; i <= nb; ++ i) {
		std :: cin >> b[i];
	}
	std :: sort(r + 1, r + 1 + nr);
	std :: sort(g + 1, g + 1 + ng);
	std :: sort(b + 1, b + 1 + nb);
	r[nr+1] = g[ng+1] = b[nb+1] = INF;
	i64 ans = LLINF;
	for(int i = 1; i <= nr; ++ i) {
		int p1 = std :: lower_bound(g + 1, g + 1 + ng, r[i]) - g - 1;
		int p2 = std :: lower_bound(b + 1, b + 1 + nb, r[i]) - b;
		ans = std :: min(ans, get(r[i], g[p1], b[p2]));
	}
	for(int i = 1; i <= nr; ++ i) {
		int p1 = std :: lower_bound(g + 1, g + 1 + ng, r[i]) - g;
		int p2 = std :: lower_bound(b + 1, b + 1 + nb, r[i]) - b - 1;
		ans = std :: min(ans, get(r[i], g[p1], b[p2]));
	}
	for(int i = 1; i <= nr; ++ i) {
		int p1 = std :: lower_bound(g + 1, g + 1 + ng, r[i]) - g;
		int p2 = std :: lower_bound(b + 1, b + 1 + nb, r[i]) - b;
		ans = std :: min(ans, get(r[i], g[p1], b[p2]));
	}
	for(int i = 1; i <= ng; ++ i) {
		int p1 = std :: lower_bound(r + 1, r + 1 + nr, g[i]) - r - 1;
		int p2 = std :: lower_bound(b + 1, b + 1 + nb, g[i]) - b;
		ans = std :: min(ans, get(r[p1], g[i], b[p2]));
	}
	for(int i = 1; i <= ng; ++ i) {
		int p1 = std :: lower_bound(r + 1, r + 1 + nr, g[i]) - r;
		int p2 = std :: lower_bound(b + 1, b + 1 + nb, g[i]) - b;
		ans = std :: min(ans, get(r[p1], g[i], b[p2]));
	}
	for(int i = 1; i <= ng; ++ i) {
		int p1 = std :: lower_bound(r + 1, r + 1 + nr, g[i]) - r;
		int p2 = std :: lower_bound(b + 1, b + 1 + nb, g[i]) - b - 1;
		ans = std :: min(ans, get(r[p1], g[i], b[p2]));
	}
	for(int i = 1; i <= nb; ++ i) {
		int p1 = std :: lower_bound(r + 1, r + 1 + nr, b[i]) - r;
		int p2 = std :: lower_bound(g + 1, g + 1 + ng, b[i]) - g;
		ans = std :: min(ans, get(r[p1], g[p2], b[i]));
	}
	for(int i = 1; i <= nb; ++ i) {
		int p1 = std :: lower_bound(r + 1, r + 1 + nr, b[i]) - r - 1;
		int p2 = std :: lower_bound(g + 1, g + 1 + ng, b[i]) - g;
		ans = std :: min(ans, get(r[p1], g[p2], b[i]));
	}
	for(int i = 1; i <= nb; ++ i) {
		int p1 = std :: lower_bound(r + 1, r + 1 + nr, b[i]) - r;
		int p2 = std :: lower_bound(g + 1, g + 1 + ng, b[i]) - g - 1;
		ans = std :: min(ans, get(r[p1], g[p2], b[i]));
	}
	std :: cout << ans << '\n';
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