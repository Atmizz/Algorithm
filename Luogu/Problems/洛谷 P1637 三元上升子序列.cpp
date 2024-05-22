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
int n, a[N];
struct Node {
	int l, r, sum;
}t1[N<<2], t2[N<<2];
void PushUp1(int k) {
	t1[k].sum = t1[ls].sum + t1[rs].sum;
}
void Build1(int l, int r, int k) {
	t1[k].l = l; t1[k].r = r;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	Build1(l, mid, ls); Build1(mid+1, r, rs);
}
void Modify1(int l, int r, int k) {
	if(l <= t1[k].l && t1[k].r <= r) {
		t1[k].sum ++;
		return ;
	}
	int mid = (t1[k].l + t1[k].r) >> 1;
	if(l <= mid) Modify1(l, r, ls);
	if(r > mid) Modify1(l, r, rs);
	PushUp1(k);
}
int Query1(int l, int r, int k) {
	if(t1[k].l >= l && t1[k]. r <= r) return t1[k].sum;
	int mid = (t1[k].l + t1[k].r) >> 1, sum = 0;
	if(l <= mid) sum += Query1(l, r, ls);
	if(r > mid) sum += Query1(l, r, rs);
	return sum;
}
void PushUp2(int k) {
	t2[k].sum = t2[ls].sum + t2[rs].sum;
}
void Build2(int l, int r, int k) {
	t2[k].l = l; t2[k].r = r;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	Build2(l, mid, ls); Build2(mid+1, r, rs);
}
void Modify2(int l, int r, int k, int x) {
	if(l <= t2[k].l && t2[k].r <= r) {
		t2[k].sum += x;
		return ;
	}
	int mid = (t2[k].l + t2[k].r) >> 1;
	if(l <= mid) Modify2(l, r, ls, x);
	if(r > mid) Modify2(l, r, rs, x);
	PushUp2(k);
}
int Query2(int l, int r, int k) {
	if(t2[k].l >= l && t2[k]. r <= r) return t2[k].sum;
	int mid = (t2[k].l + t2[k].r) >> 1, sum = 0;
	if(l <= mid) sum += Query2(l, r, ls);
	if(r > mid) sum += Query2(l, r, rs);
	return sum;
}
void solve() {
	std :: cin >> n;
	Build1(1, N-20, 1); Build2(1, N-20, 1); i64 ans = 0;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	for(int i = 1; i <= n; ++ i)
		Modify2(a[i], a[i], 1, 1);
	for(int i = 1; i <= n; ++ i) {
		Modify1(a[i], a[i], 1);
		int l = Query1(1, a[i] - 1, 1), r = Query2(a[i] + 1, N-20, 1);
		// deb(l); deb(r);
		ans += (i64)(l * r);
		// deb(l * r * Query1(a[i], a[i], 1));
		// deb(ans);
		Modify2(a[i], a[i], 1, -1);
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