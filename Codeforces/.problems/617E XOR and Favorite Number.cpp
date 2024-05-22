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
#define DEB std :: cout << "ok" << '\n';
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
const int N = 1e6 + 20;
int block, blk[N], n, m, k, a[N], sum[N];
i64 ans[N], cnt[N*10];
struct Query {
	int l, r, id;
	friend bool operator < (Query a, Query b) {
		return blk[a.l] == blk[b.l] ? a.r < b.r : blk[a.l] < blk[b.l];
	}
}q[N];
void solve() {
	std :: cin >> n >> m >> k;
	block = pow(n, 2.0 / 3);
	for(int i = 1; i <= n; ++ i) {
		blk[i] = (i - 1) / block + 1;
	}
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		sum[i] = sum[i-1] ^ a[i];
	}
	for(int i = 1; i <= m; ++ i) {
		std :: cin >> q[i].l >> q[i].r;
		q[i].id = i;
		q[i].l --;
	}
	std :: sort(q + 1, q + 1 + m);
 	int l = 0, r = 0;
 	i64 res = 0;
 	cnt[0] = 1;
	auto add = [&](int x) -> void {
		res += cnt[sum[x]^k];
		cnt[sum[x]] ++;
	};
	auto del = [&](int x) -> void {
		cnt[sum[x]] --;
		res -= cnt[sum[x]^k];
	};
	for(int i = 1; i <= m; ++ i) {
		// std :: cout << "l : " << q[i].l << ' ' << "r : " << q[i].r << nl;
		while(r < q[i].r) add(++ r);
		while(l > q[i].l) add(-- l);
		while(r > q[i].r) del(r --);
		while(l < q[i].l) del(l ++);
		ans[q[i].id] = res;
	}
	for(int i = 1; i <= m; ++ i) {
		std :: cout << ans[i] << '\n';
	}
}
int main() {
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