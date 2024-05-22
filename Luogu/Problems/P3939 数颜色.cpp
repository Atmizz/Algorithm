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
const int Range = 3e5;
const int N = 3e5 + 20;
int n, m, col[N], rt[N<<7], tot;
struct Node {
	int l, r, sum;
}t[N<<7];
void modify(int &k, int bk, int l, int r, int val, int x) {
	k = ++ tot; t[k] = t[bk]; t[k].sum += x;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	if(val <= mid) modify(t[k].l, t[bk].l, l, mid, val, x);
	else modify(t[k].r, t[bk].r, mid+1, r, val, x);
}
int query(int k1, int k2, int l, int r, int val) {
	if(l == r) return t[k1].sum - t[k2].sum;
	int mid = (l + r) >> 1;
	if(val <= mid) return query(t[k1].l, t[k2].l, l, mid, val);
	else return query(t[k1].r, t[k2].r, mid+1, r, val);
}
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> col[i];
	for(int i = 1; i <= n; ++ i)
		modify(rt[i], rt[i-1], 1, Range, col[i], 1);
	for(int i = 1; i <= m; ++ i) {
		int opt, l, r, c;
		std :: cin >> opt >> l;
		if(opt == 1) {
			std :: cin >> r >> c;
			std :: cout << query(rt[r], rt[l-1], 1, Range, c) << endl;
		} else {
			modify(rt[l], rt[l], 1, Range, col[l], -1);
			modify(rt[l], rt[l], 1, Range, col[l+1], 1);
			std :: swap(col[l], col[l+1]);
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