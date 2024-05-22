#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 550;
void solve() {
	int n, l, r, s, m = N * (N + 1) / 2;
	std :: cin >> n >> l >> r >> s;
	std :: vector <int> sum(n + 1);
	for(int i = 1; i <= n; ++ i)
		sum[i] = sum[i-1] + i;
	int len = r - l + 1;
	if(sum[len] > s || sum[n] - sum[n-len] < s) {
		std :: cout << -1 << '\n';
		return ;
	}
	int now = sum[len], ll = 1, rr = len;
	while(now < s) {
		now -= ll; now += rr + 1;
		ll ++; rr ++;
	}
	std :: map <int, int> g;
	if(s == now) {
		for(int i = ll; i <= rr; ++ i)
			g[i] = 1;
	} else {
		g[ll-1] = 1;
		for(int i = ll; i <= rr; ++ i)
			if(i != ll + now - s - 1) g[i] = 1;
	}
	int i = 0;
	for(int k = 1; k <= n; ++ k) {
		if(g[k] == 1) continue;
		if(i == l - 1) break;
		i ++; std :: cout << k << ' '; g[k] = -1;
	}
	for(int k = 1; k <= n; ++ k)
		if(g[k] == 1)
			std :: cout << k << ' ';
	for(int k = 1; k <= n; ++ k)
		if(g[k] == 0)
			std :: cout << k << ' ';
	std :: cout << '\n';
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