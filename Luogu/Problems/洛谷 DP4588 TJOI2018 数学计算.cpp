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
const int N = 1e5 + 20;
i64 p, M;
int n;
struct Node {
	int l, r;
	i64 product;
}t[N<<2];
void PushUp(int k) {
	t[k].product = t[ls].product * t[rs].product % M;
}
void Build(int l, int r, int k) {
	t[k].product = 1;
	t[k].l = l; t[k].r = r;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	Build(l, mid, ls); Build(mid + 1, r, rs);
}
void Modify(int l, int r, int k, i64 x) {
	if(t[k].l >= l && t[k].r <= r) {
		t[k].product = x % M;
		return ;
	}
	int mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid) Modify(l, r, ls, x);
	if(r > mid) Modify(l, r, rs, x);
	PushUp(k);
}
void solve() {
	std :: cin >> n >> M; p = 1ll;
	Build(1, n, 1);
	for(int i = 1; i <= n; ++ i) {
		int opt; i64 m;
		std :: cin >> opt >> m;
		if(opt == 1) Modify(i, i, 1, m);
		else Modify(m, m, 1, 1);
		std :: cout << t[1].product % M << endl;
	}
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