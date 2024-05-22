#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e6 + 5000;
struct Node {
	int l, r, sum, dep;
}t[N];
int a[N>>2], D;
void pushup(int k) {
	if(t[k].dep % 2) t[k].sum = t[ls].sum ^ t[rs].sum;
	else t[k].sum = t[ls].sum | t[rs].sum;
}
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r;
	if(l == r) {
		t[k].sum = a[l];
		t[k].dep = 1;
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls); build(mid+1, r, rs);
	t[k].dep = t[ls].dep + 1;
	pushup(k);
}
void modify(int l, int r, int k, int x) {
	if(l <= t[k].l && t[k].r <= r) {
		t[k].sum = x;
		return ;
	}
	int mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid) modify(l, r, ls, x);
	if(r > mid) modify(l, r, rs, x);
	pushup(k);
}
void solve() {
	int n, m;
	std :: cin >> n >> m;
	for(int i = 1; i <= (1 << n); ++ i)
		std :: cin >> a[i];
	build(1, (1 << n), 1);
	for(int i = 1; i <= m; ++ i) {
		int x, p;
		std :: cin >> x >> p;
		modify(x, x, 1, p);
		std :: cout << t[1].sum << endl;
		// modify(x, x, 1, a[x]);
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