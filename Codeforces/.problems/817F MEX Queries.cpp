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
const int N = 1e5 + 10;
const i64 M = 1e18 + 1;
int rt, idx;
struct Node {
	int l, r;
	short d;
	bool flag;
	Node() {
		d = l = r = flag = 0;
	}
}t[N*170];
void pushUp(int k) {
	t[k].d = t[t[k].l].d == t[t[k].r].d ? t[t[k].l].d : -1;
}
void pushDown(int k) {
	// deb(t[k].lz);
	if(t[k].d != -1) {
		if(!t[k].l) t[k].l = ++ idx;
		if(!t[k].r) t[k].r = ++ idx;
		t[t[k].l].d = t[t[k].r].d = t[k].d;
		t[t[k].l].flag = t[t[k].r].flag = 0;
	} else if(t[k].flag == 1) {
		if(!t[k].l) t[k].l = ++ idx;
		if(!t[k].r) t[k].r = ++ idx;
		if(t[t[k].l].d != -1) t[t[k].l].d ^= 1;
		else t[t[k].l].flag ^= 1;
		if(t[t[k].r].d != -1) t[t[k].r].d ^= 1;
		else t[t[k].r].flag ^= 1;
		t[k].flag = 0;
	}
}
void reverse(int &k, i64 l, i64 r, i64 rl, i64 rr) {
	if(!k) k = ++ idx;
	if(l >= rl && r <= rr) {
		if(t[k].d != -1) t[k].d ^= 1;
		else t[k].flag ^= 1;
		return ;
	}
	i64 mid = (l + r) >> 1; pushDown(k);
	if(rl <= mid) reverse(t[k].l, l, mid, rl, rr);
	if(rr > mid) reverse(t[k].r, mid+1, r, rl, rr);
	pushUp(k);
}
void update(int &k, i64 l, i64 r, i64 ul, i64 ur, i64 x) {
	if(!k) k = ++ idx;
	if(l >= ul && r <= ur) {
		t[k].d = x;
		t[k].flag = 0;
		return ;
	}
	i64 mid = (l + r) >> 1; pushDown(k);
	if(ul <= mid) update(t[k].l, l, mid, ul, ur, x);
	if(ur > mid) update(t[k].r, mid+1, r, ul, ur, x);
	pushUp(k);
}
i64 queryMex(int k, i64 l, i64 r) {
	// std :: cout << l << ' ' << r << endl;
	// deb(t[t[k].l].cnt); deb(t[t[k].r].cnt); deb(t[k].lz);
	if(l == r || !t[k].l) return l;
	pushDown(k); i64 mid = (l + r) >> 1;
	// deb(t[t[k].l].cnt); deb(t[t[k].r].cnt);
	if(t[t[k].l].d != 1) return queryMex(t[k].l, l, mid);
	return queryMex(t[k].r, mid+1, r);
}
void solve() {
	int n; i64 L = 1, R = 1e18 + 1;
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		i64 opt, l, r;
		std :: cin >> opt >> l >> r;
		if(opt == 1) update(rt, L, R*2, l, r, 1);
		else if(opt == 2) update(rt, L, R*2, l, r, 0);
		else reverse(rt, L, R*2, l, r);
		std :: cout << queryMex(rt, L, R*2) << endl;
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