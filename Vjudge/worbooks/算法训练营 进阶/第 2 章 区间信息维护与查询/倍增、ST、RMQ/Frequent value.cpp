#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
int maxx[N][22];
int query(int l, int r) {
	int k = 0;
	while(1 << k <= r - l + 1) k ++; k --;
	return std :: max(maxx[l][k], maxx[r-(1<<k)+1][k]);
}
void solve() {
	int n, m;
	while(1) {
		std :: cin >> n;
		if(n == 0) return ;
		std :: cin >> m;
		std :: vector <int> a(n+1);
		for(int i = 1; i <= n; ++ i) {
			std :: cin >> a[i];
			maxx[i][0] = 1;
			if(i > 1 && a[i] == a[i-1]) maxx[i][0] += maxx[i-1][0];
		}
		for(int j = 1; j <= 21; ++ j)
			for(int i = 1; i + (1 << j) - 1 <= n; ++ i)
				maxx[i][j] = std :: max(maxx[i][j-1], maxx[i+(1<<(j-1))][j-1]);
		while(m --) {
			int l, r, t = 0;
			std :: cin >> l >> r;
			while(l <= r && a[l-1] == a[l]) t ++, l ++;
			std :: cout << std :: max(t, query(l, r)) << endl;
		}
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