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
	int l, r, cnt;
	i64 sum;
}t[N<<6];
int n, q, rt, cnt;
i64 h[N];
void pushUp(int k) {
	t[k].cnt = t[t[k].l].cnt + t[t[k].r].cnt;
	t[k].sum = t[t[k].l].sum + t[t[k].r].sum;
}
void update(int &rt, int l, int r, int val, int x) {
	if(!rt) rt = ++ cnt;
	if(l == r) {
		t[rt].sum += 1LL * x * l;
		t[rt].cnt += x;
		return ;
	}
	int mid = (l + r) >> 1;
	if(val <= mid) update(t[rt].l, l, mid, val, x);
	else update(t[rt].r, mid+1, r, val, x);
	pushUp(rt);
}
i64 query(int &rt, int l, int r, int rk) {
	if(!rt) return 0;
	if(rk == t[rt].cnt) return t[rt].sum;
	if(l == r) return 1LL * l * rk;
	int mid = (l + r) >> 1;
	i64 res = 0;
	res = query(t[rt].l, l, mid, std :: min(rk, t[t[rt].l].cnt));
	if(rk > t[t[rt].l].cnt) res += query(t[rt].r, mid+1, r, rk - t[t[rt].l].cnt);
	return res;
}
int queryRk(int &rt, int l, int r, int rk) {
	if(!rt) return 0;
	if(l == r) return l;
	int mid = (l + r) >> 1;
	if(t[t[rt].l].cnt >= rk) return queryRk(t[rt].l, l, mid, rk);
	else return queryRk(t[rt].r, mid+1, r, rk - t[t[rt].l].cnt);
}
void solve() {
	std :: cin >> n >> q;
	for(int i = 1; i <= n; ++ i) std :: cin >> h[i];
	for(int i = 1; i <= n; ++ i)
		update(rt, 0, 1e9, h[i], 1);
	for(int i = 1; i <= q; ++ i) {
		int opt; i64 x, y;
		std :: cin >> opt >> x;
		if(opt == 1) {
			std :: cin >> y;
			update(rt, 0, 1e9, h[x], -1);
			h[x] = y;
			update(rt, 0, 1e9, h[x], 1);
		} else {
			int l = 1, r = n, res = 0;
			while(l <= r) {
				int mid = (l + r) >> 1;
				i64 q = query(rt, 0, 1e9, mid);
				int p = queryRk(rt, 0, 1e9, mid);
				if(x < 1LL * mid * p - q) r = mid - 1;
				else l = mid + 1, res = mid;
			}
			if(!res) res = 1;
			// deb(res);
			printf("%.5lf\n", 1.000 * (query(rt, 0, 1e9, res) + x) / res);
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