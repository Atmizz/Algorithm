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
const int N = 1e6 + 20;
int n, m, rt[N], a[N], tot;
struct Node {
	int l, r, val;
}t[N*40];
void build(int &k, int l, int r) {
	if(!k) k = ++ tot;
	if(l == r) {
		t[k].val = a[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(t[k].l, l, mid);
	build(t[k].r, mid+1, r);
}
void modify(int &k, int bk, int l, int r, int pos, int val) {
	if(!k) k = ++ tot;
	if(l == r) {
		t[k].val = val;
		return ;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) {
		t[k].r = t[bk].r;
		modify(t[k].l, t[bk].l, l, mid, pos, val);
	} else {
		t[k].l = t[bk].l;
		modify(t[k].r, t[bk].r, mid+1, r, pos, val);
	}
}
int query(int k, int l, int r, int pos) {
	if(l == r) return t[k].val;
	int mid = (l + r) >> 1;
	if(pos <= mid) return query(t[k].l, l, mid, pos);
	else return query(t[k].r, mid+1, r, pos);
}
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	build(rt[0], 1, n);
	for(int i = 1; i <= m; ++ i) {
		int v, opt, l, r;
		std :: cin >> v >> opt >> l;
		if(opt == 1) {
			std :: cin >> r;
			modify(rt[i], rt[v], 1, n, l, r);
		} else {
			rt[i] = rt[v];
			std :: cout << query(rt[i], 1, n, l) << endl;
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