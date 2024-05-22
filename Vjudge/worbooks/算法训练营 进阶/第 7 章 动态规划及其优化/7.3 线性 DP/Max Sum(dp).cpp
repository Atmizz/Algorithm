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
const int N = 1e5 + 21;
int n, t, f[N];
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> f[i];
	int ans = f[1], l = 1, r = 1, beg = 1;
	for(int i = 2; i <= n; ++ i) {
		if(f[i-1] >= 0) f[i] += f[i-1];
		else beg = i;
		if(ans < f[i]) ans = f[i], l = beg, r = i;
	}
	printf("Case %d:\n%d %d %d\n\n", ++t, ans, l, r);
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