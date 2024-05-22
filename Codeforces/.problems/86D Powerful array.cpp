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
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e6 + 20;
int a[N], cnt[N], n, m, l[N], r[N], block, blk[N];
i64 ans[N], sum;
struct Node {
	int l, r, id;
	friend bool operator < (Node a, Node b) {
		return (blk[a.l] ^ blk[b.l]) ? blk[a.l] < blk[b.l] : (blk[a.l] & 1 ?
		 a.r < b.r : a.r > b.r);
	}
}q[N];
void add(int x) {
	sum -= (i64)cnt[a[x]] * cnt[a[x]] * a[x];
	cnt[a[x]] ++;
	sum += (i64)cnt[a[x]] * cnt[a[x]] * a[x];
}
void del(int x) {
	sum -= (i64)cnt[a[x]] * cnt[a[x]] * a[x];
	cnt[a[x]] --;
	sum += (i64)cnt[a[x]] * cnt[a[x]] * a[x];
}
void solve() {
	std :: cin >> n >> m; block = pow(n, 2.0 / 3);
	for(int i = 1; i <= n; ++ i)
		blk[i] = (i - 1) / block + 1;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	for(int i = 1; i <= m; ++ i)
		std :: cin >> q[i].l >> q[i].r, q[i].id = i;
	std :: sort(q + 1, q + 1 + m);
	int l = 0, r = 0;
	for(int i = 1; i <= m; ++ i) {
		while(l < q[i].l) del(l ++);
		while(l > q[i].l) add(-- l);
		while(r < q[i].r) add(++ r);
		while(r > q[i].r) del(r --);
		ans[q[i].id] = sum;
	}
	for(int i = 1; i <= m; ++ i)
		std :: cout << ans[i] << endl;
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