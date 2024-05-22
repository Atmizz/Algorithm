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
const int N = 1e5 + 20;
int n, X[N<<1], m;
struct scanLine {
	int l, r, y, mk;
	friend bool operator < (scanLine a, scanLine b) {
		return a.y < b.y;
	}
}line[N<<1];
struct segmentTree {
	int l, r, sum, len;
}t[N<<4];
void pushUp(int k) {
	if(t[k].sum) {
		t[k].len = X[t[k].r+1] - X[t[k].l];
	} else {
		t[k].len = t[ls].len + t[rs].len;
	}
}
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r;
	if(l == r) {
		return ;
	}
	int mid = l + r >> 1;
	build(l, mid, ls);
	build(mid+1, r, rs);
}
void modify(int l, int r, int k, int x) {
	if(l >= X[t[k].r+1] || r <= X[t[k].l]) {
		return ;
	}
	if(X[t[k].l] >= l && X[t[k].r+1] <= r) {
		t[k].sum += x;
		pushUp(k);
		return ;
	}
	modify(l, r, ls, x);
	modify(l, r, rs, x);
	pushUp(k);
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		int x_1, y_1, x_2, y_2;
		std :: cin >> x_1 >> y_1 >> x_2 >> y_2;
		line[++m] = {x_1, x_2, y_1, 1}; X[m] = x_1;
		line[++m] = {x_1, x_2, y_2, -1}; X[m] = x_2;
	}
	std :: sort(line + 1, line + 1 + m);
	std :: sort(X + 1, X + 1 + m);
	m = std :: unique(X + 1, X + 1 + m) - X - 1;
	build(1, m-1, 1);
	i64 ans = 0;
	for(int i = 1; i < n << 1; ++ i) {
		modify(line[i].l, line[i].r, 1, line[i].mk);
		ans += 1LL * t[1].len * (line[i+1].y - line[i].y);
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