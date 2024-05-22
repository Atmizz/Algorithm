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
const int N = 5e5 + 20;
int n, b[N];
struct Value {
	int x, id;
	friend bool operator < (Value a, Value b) {
		return a.x == b.x ? a.id < b.id : a.x < b.x;
	}
}a[N];
struct Node {
	int l, r, sum;
}t[N<<2];
void PushUp(int k) {
	t[k].sum = t[ls].sum + t[rs].sum;
}
void Build(int l, int r, int k) {
	t[k].l = l; t[k].r = r;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	Build(l, mid, ls); Build(mid+1, r, rs);
}
void Modify(int l, int r, int k) {
	if(t[k].l >= l && t[k].r <= r) {
		t[k].sum ++;
		return ;
	}
	int mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid) Modify(l, r, ls);
	if(r > mid) Modify(l, r, rs);
	PushUp(k);
}
i64 Query(int l, int r, int k) {
	if(t[k].l >= l && t[k].r <= r) return t[k].sum;
	int mid = (t[k].l + t[k].r) >> 1;
	i64 sum = 0;
	if(l <= mid) sum += Query(l, r, ls);
	if(r > mid) sum += Query(l, r, rs);
	return sum;
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i].x, a[i].id = i;
	std :: sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; ++ i)
		if(a[i].x == a[i-1].x) b[a[i].id] = b[a[i-1].id];
		else b[a[i].id] = i;
	Build(1, n, 1); i64 ans = 0;
	for(int i = 1; i <= n; ++ i) {
		// deb(b[i]);
		ans += Query(b[i]+1, n, 1);
		// deb(ans);
		Modify(b[i], b[i], 1);
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