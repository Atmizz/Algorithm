#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
int n;
i64 a[N];
struct Segment {
	i64 sum, maxx;
	int l, r; 
}t[N<<2];
void pushUp(int k) {
	t[k].sum = t[ls].sum + t[rs].sum;
}
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r;
	t[k].sum = 0; t[k].maxx = 0;
	if(l == r) {
		t[k].maxx = a[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls);
	build(mid+1, r, rs);
	t[k].maxx = std :: max(t[ls].maxx, t[rs].maxx);
}
void modify(int l, int r, int k, i64 x) {
	if(t[k].l >= l && t[k].r <= r) {
		t[k].sum = x;
		return ;
	}
	int mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid) {
		modify(l, r, ls, x);
	} 
	if(r > mid) {
		modify(l, r, rs, x);
	}
	pushUp(k);
}
i64 querySum(int l, int r, int k) {
	if(t[k].l >= l && t[k].r <= r) {
		return t[k].sum;
	}
	int mid = (t[k].l + t[k].r) >> 1;
	i64 sum = 0;
	if(l <= mid) {
		sum += querySum(l, r, ls);
	}
	if(r > mid) {
		sum += querySum(l, r, rs);
	}
	return sum;
}
i64 queryMax(int l, int r, int k) {
	if(t[k].l >= l && t[k].r <= r) {
		return t[k].maxx;
	}
	int mid = (t[k].l + t[k].r) >> 1;
	i64 maxx = 0;
	if(l <= mid) {
		maxx = std :: max(maxx, queryMax(l, r, ls));
	}
	if(r > mid) {
		maxx = std :: max(maxx, queryMax(l, r, rs));
	}
	return maxx;
}
bool check(int l, int r, int k) {
	std :: cout << l << ' ' << r << '\n';
	if(l >= r) {
		return true;
	}
	i64 sum = querySum(l, r, 1);
	i64 maxx = queryMax(l, r, 1);
	int mid = (l + r) >> 1;
	return (maxx >= sum) & check(mid+1, r, 1);
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	build(1, n, 1);
	for(int i = 1; i <= n; ++ i) {
		modify(i, i, 1, a[i]);
		bool flag = check(1, i, 1);
		if(a[i] > 0 && a[i-1] > 0) {
			flag = 0;
		}
		if(flag == 0) {
			std :: cout << "NO\n";
			return ;
		}
	}
	std :: cout << "YES\n";
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}