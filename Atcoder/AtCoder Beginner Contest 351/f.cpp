#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define mk std :: make_pair
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << endl;
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define int long long
using i64 = long long;
typedef unsigned long long ull;
template <class T>
T max(T a, T b) {
	return a > b ? a : b;
}
template <class T>
T min(T a, T b) {
	return a < b ? a : b;
}
template <class T>
T abs(T a) {
	return a < 0 ? -a : a;
}
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e6 + 20;
struct Node {
	int l, r;
	int num;
	i64 sum;
}t[N<<2];
int a[N], b[N], n;
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r;
	if(l == r) {
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls);
	build(mid+1, r, rs);
}
void pushUp(int k) {
	t[k].sum = t[ls].sum + t[rs].sum;
	t[k].num = t[ls].num + t[rs].num;
}
void modify(int l, int r, int k, int z) {
	if(t[k].l >= l && t[k].r <= r) {
		t[k].num ++;
		t[k].sum += z;
		return ;
	}
	int mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid) {
		modify(l, r, ls, z);
	}
	if(r > mid) {
		modify(l, r, rs, z);
	}
	pushUp(k);
}
i64 querySum(int l, int r, int k) {
	if(t[k].l >= l && t[k].r <= r) {
		return t[k].sum;
	}
	i64 sum = 0;
	int mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid) {
		sum += querySum(l, r, ls);
	}
	if(r > mid) {
		sum += querySum(l, r, rs);
	}
	return sum;
}
int queryNum(int l, int r, int k) {
	if(t[k].l >= l && t[k].r <= r) {
		return t[k].num;
	}
	int num = 0;
	int mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid) {
		num += queryNum(l, r, ls);
	}
	if(r > mid) {
		num += queryNum(l, r, rs);
	}
	return num;
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		b[i] = a[i];
	}
	std :: sort(b + 1, b + 1 + n);
	int m = std :: unique(b + 1, b + 1 + n) - b - 1;
	// deb(m);
	build(1, m, 1);
	i64 ans = 0;
	for(int i = n; i >= 1; -- i) {
		int pos = std :: lower_bound(b + 1, b + 1 + m, a[i]) - b;
		ans += querySum(pos, m, 1) - 1LL * queryNum(pos, m, 1) * a[i];
		modify(pos, pos, 1, a[i]);
	}
	std :: cout << ans;
}
signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	//std :: cin >> _; 
	while(_ --) solve();
	return 0;
}