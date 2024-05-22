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
const int N = 2e5 + 20;
struct Node {
	int l, r;
	i64 maxx;
}t[N<<2];
i64 val[N];
void pushUp(int k) {
	t[k].maxx = max(t[ls].maxx, t[rs].maxx);
}
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r;
	if(l == r) {
		t[k].maxx = val[l];
		return ;
	}
	int mid = l + r >> 1;
	build(l, mid, ls);
	build(mid+1, r, rs);
	pushUp(k);
}
i64 query(int l, int r, int k) {
	if(r < l) {
		return LLONG_MIN / 2;
	}
	if(t[k].l >= l && t[k].r <= r) {
		return t[k].maxx;
	}
	int mid = (t[k].l + t[k].r) >> 1;
	i64 maxx = LLONG_MIN;
	if(l <= mid) {
		maxx = max(maxx, query(l, r, ls));
	}
	if(r > mid) {
		maxx = max(maxx, query(l, r, rs));
	}
	return maxx;
}
void solve() {
	int n, k;
	std :: cin >> n >> k;
	std :: vector <int> a(n+1);
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	std :: priority_queue <Node> q;
	i64 sum = 0;
	for(int i = 1; i <= n; ++ i) {
		sum += a[i];
		if(i >= k) {
			sum -= a[i-k];
			val[i] = sum;
		} else {
			val[i] = LLONG_MIN / 2;
		}
	}
	build(1, n, 1);
	i64 ans = LLONG_MIN;
	sum = 0;
	for(int i = 1; i < k; ++ i) {
		sum += a[i];
	}
	for(int i = k; i <= n; ++ i) {
		sum += a[i];
		sum -= a[i-k];
		ans = max(ans, sum + max(query(1, i-k, 1), query(i+k, n, 1)));
	}
	std :: cout << ans << nl;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}