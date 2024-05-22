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
int n, m, a[N], q1[N], q2[N];
void solve() {
	std :: cin >> n >> m;
	int cnt1 = 0, cnt2 = 0;
	i64 res = 0;
	memset(q1, 0, sizeof q1);
	memset(q2, 0, sizeof q2);
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		res += a[i];
	}
	for(int i = 1; i <= n; ++ i) {
		int x; std :: cin >> x;
		if(x == 1) {
			q1[++cnt1] = a[i];
		} else {
			q2[++cnt2] = a[i];
		}
	}
	if(res < m) {
		std :: cout << -1 << '\n';
		return ;
	}
	std :: sort(q1 + 1, q1 + 1 + cnt1, std :: greater<int>());
	std :: sort(q2 + 1, q2 + 1 + cnt2, std :: greater<int>());
	int val = 0, pos1 = 1, pos2 = 1, ans = 0;
	while(val < m) {
		if(q1[pos1] + val >= m) {
			val += q1[pos1];
			pos1 ++;
			ans ++;
		} else if(q2[pos2] >= q1[pos1] + q1[pos1+1]) {
			val += q2[pos2];
			pos2 ++;
			ans += 2;
		} else {
			val += q1[pos1];
			pos1 ++;
			ans ++;
		}
	}
	std :: cout << ans << '\n';
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