#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
void solve() {
	int n, m, k;
	std :: cin >> n >> m >> k;
	std :: vector <int> a(n+1), b(m+1);
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	for(int i = 1; i <= m; ++ i) {
		std :: cin >> b[i];
	}
	std :: map <int, int> mp, p;
	int cnt = 0;
	int ans = 0;
	for(int i = 1; i <= m; ++ i) {
		mp[b[i]] ++;
	}
	for(int i = 1; i <= m; ++ i) {
		p[a[i]] ++;
		if(mp.count(a[i]) && p[a[i]] <= mp[a[i]]) {
			cnt ++;
		}
	}
	ans += (cnt >= k);
	// deb(cnt);
	for(int i = 2; i <= n; ++ i) {
		int j = i + m - 1;
		if(j > n) {
			break;
		}
		p[a[i-1]] --;
		if(mp.count(a[i-1]) && p[a[i-1]] < mp[a[i-1]]) {
			cnt --;
		}
		p[a[j]] ++;
		if(mp.count(a[j]) && p[a[j]] <= mp[a[j]]) {
			cnt ++;
		}
		// deb(cnt);
		ans += (cnt >= k);
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