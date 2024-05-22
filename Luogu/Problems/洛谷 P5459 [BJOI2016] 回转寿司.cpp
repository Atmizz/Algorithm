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
const i64 MaxN = 1e10;
struct Node {
	int l, r, cnt;
}t[N<<6];
i64 sum[N], L, R, ans;
int n, rt, idx;
void pushUp(int rt) {
	t[rt].cnt = t[t[rt].l].cnt + t[t[rt].r].cnt;
}
void update(int &rt, i64 l, i64 r, i64 x) {
	if(!rt) rt = ++ idx;
	if(l == r) {
		t[rt].cnt ++;
		return ;
	} i64 mid = (l + r) >> 1;
	if(x <= mid) update(t[rt].l, l, mid, x);
	else update(t[rt].r, mid+1, r, x);
	pushUp(rt);
}
int query(int rt, i64 l, i64 r, i64 ql, i64 qr) {
	if(!rt) return 0;
	if(l >= ql && r <= qr) return t[rt].cnt;
	i64 mid = (l + r) >> 1, cnt = 0;
	if(ql <= mid) cnt += query(t[rt].l, l, mid, ql, qr);
	if(qr > mid) cnt += query(t[rt].r, mid+1, r, ql, qr);
	return cnt;
}
void solve() {
	std :: cin >> n >> L >> R;
	for(int i = 1; i <= n; ++ i) {
		i64 a; std :: cin >> a;
		sum[i] = sum[i-1] + a;
	}
	update(rt, -MaxN, MaxN, 0);
	for(int i = 1; i <= n; ++ i) {
		// deb(query(rt, (i64)N * Mod * (-1ll), (i64)N * Mod, sum[i] - R, sum[i] - L));
		ans += query(rt, -MaxN, MaxN, sum[i] - R, sum[i] - L);
		update(rt, -MaxN, MaxN, sum[i]);
	}
	std :: cout << ans;
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