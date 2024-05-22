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
const int N = 1e5 + 20;
int n, m, a[N], cnt[N], sum[20][N];
int lowbit(int x) {
	return x & -x;
}
void add(int p, int x) {
	for(; x <= n; x += lowbit(x)) {
		sum[p][x] ++;
	}
}
int query(int p, int x) {
	int res = 0;
	for(; x; x -= lowbit(x)) {
		res += sum[p][x];
	}
	return res;
}
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		a[i] --;
		add(a[i], i);
		cnt[a[i]] ++;
	}
	std :: vector <int> dp(1 << m);
	// dp_i 表示 i 这个状态下的移动数量。
	for(int _ = 1; _ < 1 << m; ++ _) {
		int num = 0;
		dp[_] = INF;
		for(int i = 0; i < m; ++ i) {
			if(_ >> i & 1) {
				num += cnt[i];
			}
		}
		for(int i = 0; i < m; ++ i) {
			if(!(_ >> i & 1)) {
				continue;
			}
			// deb(query(i, num) - query(i, num-cnt[i]));
			dp[_] = std :: min(dp[_], dp[_-(1<<i)] + cnt[i] - query(i, num) + query(i, num-cnt[i]));
		}
	}
	std :: cout << dp[(1<<m)-1];
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