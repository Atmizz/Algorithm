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
const int Range = 1e9;
const int N = 2e5 + 20;
int n, m, a[N], rt[N], tot;
struct Node {
	int l, r, sum;
}t[N*40];
void insert(int &k, int bk, int l, int r, int val) {
	if(!k) k = ++ tot; t[k].sum = t[bk].sum; t[k].sum ++;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	if(val <= mid) {
		t[k].r = t[bk].r;
		insert(t[k].l, t[bk].l, l, mid, val);
	}
	else {
		t[k].l = t[bk].l;
		insert(t[k].r, t[bk].r, mid+1, r, val);
	}
}
int query(int k1, int k2, int l, int r, int x) {
	// std :: cout << l << ' ' << r << endl;
	if(l == r) return l;
	int res = t[t[k2].l].sum - t[t[k1].l].sum;
	int mid = (l + r) >> 1;
	if(x <= res) return query(t[k1].l, t[k2].l, l, mid, x);
	else return query(t[k1].r, t[k2].r, mid+1, r, x - res);
}
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	for(int i = 1; i <= n; ++ i)
		insert(rt[i], rt[i-1], -Range, Range, a[i]);
	for(int i = 1; i <= m; ++ i) {
		int l, r, k;
		std :: cin >> l >> r >> k;
		std :: cout << query(rt[l-1], rt[r], -Range, Range, k) << endl;
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