#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 5e4 + 20;
int n, q, maxx[N][22], minn[N][22];
int query(int l, int r) {
	int k = 0;
	while(1 << k <= r - l + 1)
		k ++; k --;
	return std :: max(maxx[l][k], maxx[r-(1<<k)+1][k]) - std :: min(minn[l][k], minn[r-(1<<k)+1][k]);
}
void solve() {
	std :: cin >> n >> q;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> maxx[i][0], minn[i][0] = maxx[i][0];
	for(int j = 1; j <= 21; ++ j)
		for(int i = 1; i + (1 << j) - 1 <= n; ++ i) {
			maxx[i][j] = std :: max(maxx[i][j-1], maxx[i+(1<<(j-1))][j-1]);
			minn[i][j] = std :: min(minn[i][j-1], minn[i+(1<<(j-1))][j-1]);
		}
	while(q --) {
		int l, r;
		std :: cin >> l >> r;
		printf("%d\n", query(l, r));
	}
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