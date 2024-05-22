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
const int N = 1e5 + 20;
struct Node {
	int l, r, sum;
}t[2][N<<2];
int n, m;
std :: string str;
void pushUp(int k, int ch) {
	t[ch][k].sum = t[ch][ls].sum + t[ch][rs].sum;
}
void build(int l, int r, int k, int ch) {
	t[ch][k].l = l; t[ch][k].r = r;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	build(l, mid, ls, ch); build(mid+1, r, rs, ch);
}
void modify(int l, int r, int k, int x, int ch) {
	if(t[ch][k].l >= l && t[ch][k].r <= r) {
		t[ch][k].sum += x;
		return ;
	}
	int mid = (t[ch][k].l + t[ch][k].r) >> 1;
	if(l <= mid) modify(l, r, ls, x, ch);
	if(r > mid) modify(l, r, rs, x, ch);
	pushUp(k, ch);
}
int query(int l, int r, int k, int ch) {
	if(t[ch][k].l >= l && t[ch][k].r <= r) return t[ch][k].sum;
	int mid = (t[ch][k].l + t[ch][k].r) >> 1, sum = 0;
	if(l <= mid) sum += query(l, r, ls, ch);
	if(r > mid) sum += query(l, r, rs, ch);
	return sum;
}
void solve() {
	std :: cin >> n >> m;
	build(1, n, 1, 0);
	build(1, n, 1, 1);
	for(int i = 1; i <= m; ++ i) {
		int opt, l, r;
		std :: cin >> opt >> l >> r;
		if(opt == 1) modify(l, l, 1, 1, 0), modify(r, r, 1, 1, 1);
		else std :: cout << query(1, r, 1, 0) - query(1, l-1, 1, 1) << endl;
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