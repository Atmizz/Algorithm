#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
int f[N][25];
i64 n, m;
int query(int l, int r) {
	int k = std :: log2(r - l + 1);
	return std :: max(f[l][k], f[r-(1<<k)+1][k]);
}
bool check(int x) {
	i64 res = 0; int y = n / x;
	for(int i = 0; i < x; ++ i)
		res += query(1+i*y, (i+1)*y);
	// deb(res);
	return res > m;
}
void solve() {
	while(1) {
		std :: cin >> n >> m;
		if(n == -1) return ;
		for(int i = 1; i <= n; ++ i)
			std :: cin >> f[i][0];
		for(int j = 1; (1 << j) <= n; ++ j)
			for(int i = 1; i + (1 << j) - 1 <= n; ++ i)
				f[i][j] = std :: max(f[i][j-1], f[i+(1<<(j-1))][j-1]);
		i64 l = 1, r = n, ans = -1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(check(mid)) r = mid - 1, ans = mid;
			else l = mid + 1;
		}
		std :: cout << ans << endl;
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