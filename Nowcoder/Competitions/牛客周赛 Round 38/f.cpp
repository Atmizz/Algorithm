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
int n, a[N], blk[N], block, m, b[N], ans[N], cnt, sum[N];
struct Query {
	int l, r, id;
	friend bool operator < (Query a, Query b) {
		return blk[a.l] == blk[b.l] ? a.r < b.r : blk[a.l] < blk[b.l];
	}
}q[N];
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		b[i] = a[i];
	}
	std :: sort(b + 1, b + 1 + n);
	for(int i = 1; i <= n; ++ i) {
		a[i] = std :: lower_bound(b + 1, b + 1 + n, a[i]) - b;
	}
	block = sqrt(n);
	for(int i = 1; i <= n; ++ i) {
		blk[i] = (i - 1) / block + 1;
	}
	for(int i = 1; i <= m; ++ i) {
		std :: cin >> q[i].l >> q[i].r;
		q[i].id = i;
	}
	std :: sort(q + 1, q + 1 + m);
	int l = 1, r = 0;
	auto add = [&](int x) {
		sum[a[x]] ++;
		if(sum[a[x]] == 3) {
			cnt ++;
		}
		if(l <= x - 1 && a[x-1] != a[x] && sum[a[x]] > 1) {
			cnt ++;
		}
		if(r >= x + 1 && a[x+1] != a[x] && sum[a[x]] > 1) {
			cnt ++;
		}
	};
	auto del = [&](int x) {
		sum[a[x]] --;
		if(sum[a[x]] == 2) {
			cnt --;
		}
		if(l <= x - 1 && a[x-1] != a[x] && sum[a[x]] >= 1) {
			cnt --;
		}
		if(r >= x + 1 && a[x+1] != a[x] && sum[a[x]] >= 1) {
			cnt --;
		}
	};
	for(int i = 1; i <= m; ++ i) {
		while(l < q[i].l) del(l ++);
		while(l > q[i].l) add(-- l);
		while(r < q[i].r) add(++ r);
		while(r > q[i].r) del(r --);
		ans[q[i].id] = cnt;
	}
	for(int i = 1; i <= m; ++ i) {
		std :: cout << (ans[i] ? "YES\n" : "NO\n");
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