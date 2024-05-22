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
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
struct Node {
	int l, r, sum;
}t[N*50];
int n, q, a[N], tot, rt;

void pushUp(int k) {
	t[k].sum = 0;
	if(t[t[k].l].l == 0 && t[t[k].l].r == 0) {
		if(t[t[k].l].sum > 0) t[k].sum ++;
	} else t[k].sum += t[t[k].l].sum;

	if(t[t[k].r].l == 0 && t[t[k].r].r == 0) {
		if(t[t[k].r].sum > 0) t[k].sum ++;
	} else t[k].sum += t[t[k].r].sum;
}
void Insert(int &k, int l, int r, int x, int val) {
	if(!k) k = ++ tot;
	if(l == r) {
		t[k].sum += val;
		return ;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) Insert(t[k].l, l, mid, x, val);
	else Insert(t[k].r, mid + 1, r, x, val);
	pushUp(k);
}
int query(int k, int l, int r) {
	// deb(t[k].sum);
	if(l == r) return l;
	int mid = (l + r) >> 1;
	if(t[t[k].l].sum < mid - l + 1) return query(t[k].l, l, mid);
	return query(t[k].r, mid+1, r);
}

void solve() {
	std :: cin >> n >> q;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	for(int i = 1; i <= n; ++ i)
		Insert(rt, 0, Range, a[i], 1);
	while(q --) {
		int opt, x;
		std :: cin >> opt >> x;
		Insert(rt, 0, Range, a[opt], -1);
		Insert(rt, 0, Range, x, 1);
		std :: cout << query(rt, 0, Range) << endl;
		a[opt] = x;
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