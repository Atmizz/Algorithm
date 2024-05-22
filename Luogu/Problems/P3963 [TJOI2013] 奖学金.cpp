#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define int long long
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Range = 1e5;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
int c, n, f, rt[N*40], tot;
struct stu {
	i64 a, b;
	friend bool operator < (stu a, stu b) {
		return a.a < b.a;
	}
}s[N];
struct Node {
	int l, r, cnt;
	i64 sum;
}t[N*40];
void pushUp(int k) {
	t[k].sum = t[t[k].l].sum + t[t[k].r].sum;
	t[k].cnt = t[t[k].l].cnt + t[t[k].r].cnt;
}
void modify(int &k, int bk, int l, int r, int val) {
	if(!k) k = ++ tot;
	if(l == r) {
		t[k].sum = t[bk].sum + val;
		t[k].cnt = t[bk].cnt + 1;
		return ;
	}
	int mid = (l + r) >> 1;
	if(val <= mid) {
		t[k].r = t[bk].r;
		modify(t[k].l, t[bk].l, l, mid, val);
	} else {
		t[k].l = t[bk].l;
		modify(t[k].r, t[bk].r, mid+1, r, val);
	}
	pushUp(k);
}
i64 query(int k1, int k2, int l, int r, int x) {
	// std :: cout << l << ' ' << r << endl;
	if(l == r) return l * x;
	if(t[k1].cnt - t[k2].cnt <= x)
		return t[k1].sum - t[k2].sum;
	int mid = (l + r) >> 1;
	int res = t[t[k1].l].cnt - t[t[k2].l].cnt;
	if(res >= x)
		return query(t[k1].l, t[k2].l, l, mid, x);
	return query(t[k1].l, t[k2].l, l, mid, res) + 
		query(t[k1].r, t[k2].r, mid+1, r, x-res);
}
void solve() {
	std :: cin >> n >> c >> f;
	for(int i = 1; i <= c; ++ i)
		std :: cin >> s[i].a >> s[i].b;
	std :: sort(s + 1, s + 1 + c);

	for(int i = 1; i <= c; ++ i)
		modify(rt[i], rt[i-1], 0, Range, s[i].b);
	// for(int i = 1; i <= c; ++ i) {
	// 	std :: cout << query(rt[i], rt[0], 0, Range, 1) << endl;
	// }
	n >>= 1;
	for(int i = c - n; i >= n + 1; -- i) {
		i64 sum = query(rt[c], rt[i], 0, Range, n) + 
			query(rt[i-1], rt[0], 0, Range, n) + s[i].b;
		if(sum > f) continue;
		std :: cout << s[i].a;
		return ;
	}
	std :: cout << -1;
}
signed main() {
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