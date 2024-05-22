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
const int N = 1e5 + 2;
int sum[500][N];
int n, m, a[N], cnt[N], b[N], origin[N];
int lowbit(int x) {
	return x & -x;
}
void add(int x, int k) {
	for(; x <= n; x += lowbit(x)) {
		sum[k][x] ++;
	}
}
int query(int x, int k) {
	int s = 0;
	for(; x; x -= lowbit(x)) {
		s += sum[k][x];
	}
	return s;
}
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		b[i] = a[i];
	}
	std :: sort(b + 1, b + 1 + n);
	int res = std :: unique(b + 1, b + 1 + n) - b;
	std :: vector <int> st;
	for(int i = 1; i <= n; ++ i) {
		int tmp = a[i];
		a[i] = std :: lower_bound(b + 1, b + res, a[i]) - b;
		origin[a[i]] = tmp;
		cnt[a[i]] ++;
		// deb(a[i]);
		// deb(cnt[a[i]])
		if(cnt[a[i]] == a[i]) {
			// deb(a[i]);
			// deb(cnt[a[i]])
			st.push_back(a[i]);
		}
	}
	for(int j = 0; j < st.size(); ++ j) {
		for(int i = 1; i <= n; ++ i) {
			if(a[i] == st[j]) {
				add(i, j);
			}
		}
	}
	while(m --) {
		int l, r;
		std :: cin >> l >> r;
		int ans = 0;
		for(int j = 0; j < st.size(); ++ j) {
			ans += (query(r, j) - query(l-1, j) == origin[st[j]]);
		}
		std :: cout << ans << '\n';
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