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
char a[N], b[N];
int n;
void solve() {
	scanf("%d", &n);
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	if(a[1] != b[1] || a[n] != b[n]) {
		std :: cout << -1 << '\n';
		return ;
	}
	int c1 = (a[n] == '0'), c2 = (b[n] == '0');
	for(int i = 1; i < n; ++ i) {
		if(a[i] == '0' && a[i+1] == '1') {
			c1 ++;
		}
	}
	for(int i = 1; i < n; ++ i) {
		if(b[i] == '0' && b[i+1] == '1') {
			c2 ++;
		}
	}
	// std :: cout << c1 << ' ' << c2 << '\n';
	if(c1 != c2) {
		std :: cout << -1 << '\n';
		return ;
	}
	i64 ans = 0;
	int i = 1, j = 1;
	for(int i = 1; i <= n; ++ i) {
		if(a[i] == '0') {
			continue;
		}
		// deb(i);
		int cnt1 = 0, k = i;
		while(a[k] == '1' && k <= n) {
			cnt1 ++;
			k ++;
		}
		for(; j <= n; ++ j) {
			if(b[j] == '0') {
				continue ;
			}
			int cnt2 = 0, t = j;
			while(b[t] == '1' && t <= n) {
				cnt2 ++;
				t ++;
			}
			// deb(i - j);
			// deb(t - k);
			// std :: cout << t << ' ' << k << '\n';
			ans += std :: abs(i - j) + std :: abs(t - k);
			j = t;
			break;
		}
		i = k - 1;
	}
	std :: cout << ans << '\n';
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}