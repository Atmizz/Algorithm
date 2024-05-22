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
const int Range = 1e5;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
int n, k, a[N], rt[N*40], q, tot;
struct Node {
	int l, r, sum;
}t[N*40];
void Modify(int &k, int bk, int l, int r, int val) {
	if(!k) k = ++ tot;
	t[k].sum = t[bk].sum + 1;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	if(val <= mid) {
		t[k].r = t[bk].r;
		Modify(t[k].l, t[bk].l, l, mid, val);
	} else {
		t[k].l = t[bk].l;
		Modify(t[k].r, t[bk].r, mid+1, r, val);
	}
}
int Query(int k1, int k2, int l, int r) {
	if(l == r) return ((t[k1].sum - t[k2].sum > k) ? k : (t[k1].sum - t[k2].sum));
	int mid = (l + r) >> 1;
	return Query(t[k1].l, t[k2].l, l, mid) + Query(t[k1].r, t[k2].r, mid+1, r);
}
void solve() {
	std :: cin >> n >> k;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	for(int i = 1; i <= n; ++ i)
		Modify(rt[i], rt[i-1], 1, Range, a[i]);
	std :: cin >> q;
	for(int i = 1; i <= q; ++ i) {
		int l, r; std :: cin >> l >> r;
		if(l > r) std :: swap(l, r); 
		std :: cout << Query(rt[r], rt[l-1], 1, Range) << endl;
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
