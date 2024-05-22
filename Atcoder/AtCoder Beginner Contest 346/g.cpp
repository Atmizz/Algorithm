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
int n, a[N], lst[N], nxt[N], m;
struct scanLine {
	int l, r, h, mk;
	friend bool operator < (scanLine a, scanLine b) {
		return a.h < b.h;
	}
}line[N<<1];
struct segmentTree {
	int l, r, sum, minn, lz;
}t[N<<2];
void pushUp(int k) {
	if(t[ls].minn > t[rs].minn) {
		t[k].minn = t[rs].minn;
		t[k].sum = t[rs].sum;
	} else if(t[ls].minn < t[rs].minn) {
		t[k].minn = t[ls].minn;
		t[k].sum = t[ls].sum;
	} else {
		t[k].minn = t[rs].minn;
		t[k].sum = t[ls].sum + t[rs].sum;
	}
}
void pushDown(int k) {
	t[ls].lz += t[k].lz;
	t[rs].lz += t[k].lz;
	t[ls].minn += t[k].lz;
	t[rs].minn += t[k].lz;
	t[k].lz = 0;
}
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r;
	if(l == r) {
		t[k].sum = r - l + 1;
		return ;
	}
	int mid = l + r >> 1;
	build(l, mid, ls);
	build(mid+1, r, rs);
	pushUp(k);
}
void modify(int l, int r, int k, int x) {
	if(l <= t[k].l && t[k].r <= r) {
		t[k].lz += x;
		t[k].minn += x;
		return ;
	}
	if(t[k].lz) {
		pushDown(k);
	}
	int mid = t[k].l + t[k].r >> 1;
	if(l <= mid) {
		modify(l, r, ls, x);
	}
	if(r > mid) {
		modify(l, r, rs, x);
	}
	pushUp(k);
}
void solve() {
	std :: cin >> n;
	i64 ans = 0;
	std :: map <int, int> mp;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		if(!mp[a[i]]) {
			lst[i] = 0;
		} else {
			lst[i] = mp[a[i]];
		}
		mp[a[i]] = i;
	}
	mp.clear();
	for(int i = n; i >= 1; -- i) {
		if(!mp[a[i]]) {
			nxt[i] = n + 1;
		} else {
			nxt[i] = mp[a[i]];
		}
		mp[a[i]] = i;
	}
	for(int i = 1; i <= n; ++ i) {
		line[++m] = {lst[i]+1, i, i, 1};
		line[++m] = {lst[i]+1, i, nxt[i], -1};
	}
	std :: sort(line + 1, line + 1 + m);
	// for(int i = 1; i <= m; ++ i) {
	// 	std :: cout << line[i].l << ' ' << line[i].r << ' ' << line[i].h << ' ' << line[i].mk << '\n';
	// }
	// DEB
	build(1, N-20, 1);
	int j = 1;
	for(int i = 1; i <= N - 20; ++ i) {
		while(j <= m && line[j].h <= i) {
			// std :: cout << line[j].l << ' ' << line[j].r << ' ' << line[j].h << ' ' << line[j].mk << '\n';
			modify(line[j].l, line[j].r, 1, line[j].mk);
			// deb(j);
			// deb(t[1].sum);
			j ++;
		}
		int res = ans;
		ans += (N-20) - (t[1].minn == 0 ? t[1].sum : 0);
		// if(res != ans) {
		// 	deb(i);
		// 	deb(ans);
		// }
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