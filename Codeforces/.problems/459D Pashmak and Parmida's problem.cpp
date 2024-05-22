// LUOGU_RID: 149276095
#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
#define int long long
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e6 + 20;
int n, a[N], b[N], sum[N], res[N];
i64 c[N];
inline int lowbit(int x) {
	return x & -x;
}
void add(int x, int k) {
	for(; x <= n; x += lowbit(x)) {
		c[x] += k;
	}
}
i64 query(int x) {
	i64 sum = 0;
	for(; x; x -= lowbit(x)) {
		sum += c[x];
	}
	return sum;
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		b[i] = a[i];
	}
	std :: sort(b + 1, b + 1 + n);
	for(int i = 1; i <= n; ++ i) {
		a[i] = std :: lower_bound(b + 1, b + 1 + n, a[i]) - b;
	}
	for(int i = n; i >= 1; -- i) {
		sum[a[i]] ++;
		add(sum[a[i]], 1);
	}
	i64 ans = 0;
	for(int i = 1; i <= n; ++ i) {
		res[a[i]] ++;
		add(sum[a[i]], -1);
		sum[a[i]] --;
		ans += query(res[a[i]]-1);
	}
	std :: cout << ans;
}
signed main() {
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