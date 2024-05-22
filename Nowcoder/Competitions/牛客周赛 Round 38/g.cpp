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
const int N = 1e6 + 20;
int n, a[N], m;
i64 k;
std :: vector <i64> pre(N), suf(N);
inline int lowbit(int x) {
	return x & -x;
}
void add(std :: vector <i64> &t, int x, int y) {
	while(x <= m) {
		t[x] += y;
		x += lowbit(x);
	}
}
i64 query(std :: vector <i64> &t, int x) {
	i64 s = 0;
	while(x) {
		s += t[x];
		x -= lowbit(x);
	}
	return s;
}
void solve() {
	std :: cin >> n >> k;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	m = *std :: max_element(a + 1, a + 1 + n);
	i64 sum = 0;
	for(int i = n; i >= 1; -- i) {
		sum += query(suf, a[i]-1);
		add(suf, a[i], 1);
	}
	i64 ans = (sum >= k);
	for(int i = 1, j = 1; i <= n; ++ i) {
		add(suf, a[i], -1);
		sum -= query(suf, a[i]-1);
		sum -= query(pre, m) - query(pre, a[i]);
		while(j <= i && sum < k) {
			add(pre, a[j], 1);
			sum += query(pre, m) - query(pre, a[j]);
			sum += query(suf, a[j]-1);
			++ j;
		}
		ans += i - j + 1;
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