#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define mk std :: make_pair
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << endl;
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
typedef unsigned long long ull;
template <class T>
T max(T a, T b) {
	return a > b ? a : b;
}
template <class T>
T min(T a, T b) {
	return a < b ? a : b;
}
template <class T>
T abs(T a) {
	return a < 0 ? -a : a;
}
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e4 + 20;
int n, m, k;
i64 dp[N][110], a[N];
struct Node {
	int l, r;
	i64 maxx;
}t[N<<2][110];
void pushUp(int k, int id) {
	t[k][id].maxx = max(t[ls][id].maxx, t[rs][id].maxx);
}
void build(int l, int r, int k, int id) {
	t[k][id].l = l; t[k][id].r = r;
	if(l == r) {
		t[k][id].maxx = LLONG_MIN / 2;
		return ;
	}
	int mid = l + r >> 1;
	build(l, mid, ls, id);
	build(mid+1, r, rs, id);
}
void modify(int l, int r, int k, i64 val, int id) {
	if(t[k][id].l == t[k][id].r) {
		t[k][id].maxx = val;
		return ;
	}
	int mid = t[k][id].l + t[k][id].r >> 1;
	if(l <= mid) {
		modify(l, r, ls, val, id);
	}
	if(r > mid) {
		modify(l, r, rs, val, id);
	}
	pushUp(k, id);
}
i64 query(int l, int r, int k, int id) {
	if(t[k][id].l >= l && t[k][id].r <= r) {
		return t[k][id].maxx;
	}
	int mid = t[k][id].l + t[k][id].r >> 1;
	i64 maxx = INT_MIN;
	if(l <= mid) {
		maxx = max(maxx, query(l, r, ls, id));
	}
	if(r > mid) {
		maxx = max(maxx, query(l, r, rs, id));
	}
	return maxx;
}
void solve() {
	std :: cin >> n >> m >> k;
	for(int i = 1; i <= m; ++ i) {
		build(1, n, 1, i);
	}
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		modify(i, i, 1, a[i], 1);
		dp[i][1] = a[i];
	}
	for(int i = 2; i <= m; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			i64 res = query(1, j - k, 1, i-1);
			dp[j][i] = max((i64)INT_MIN, res + a[j]);
			modify(j, j, 1, dp[j][i], i);
		}
	}
	i64 ans = INT_MIN;
	for(int i = 1; i <= n; ++ i) {
		ans = max(ans, dp[i][m]);
	}
	// for(int i = 1; i <= n; ++ i) {
	// 	for(int j = 1; j <= m; ++ j) {
	// 		std :: cout << dp[i][j] << " \n"[j == m];
	// 	}
	// }
	std :: cout << ans;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	//std :: cin >> _; 
	while(_ --) solve();
	return 0;
}