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
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N =;
void solve() {
	int n, m; std :: cin >> n >> m;
	std :: vector <int> a(n+1), b(n+1), c(m+1), pos[n+1], ans(m+1), plan[n+1];
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	for(int i = 1; i <= n; ++ i)
		std :: cin >> b[i];
	for(int i = 1; i <= m; ++ i)
		std :: cin >> c[i];

	int cnt = 0;
	for(int i = 1; i <= n; ++ i)
		if(a[i] != b[i]) pos[b[i]].push_back(i), cnt ++;
		else plan[b[i]].push_back(i);

	if(cnt == 0) {
		for(int i = 1; i <= n; ++ i)
			if(b[i] == c[m]) {
				std :: cout << "YES\n";
				for(int j = 1; j <= m; ++ j)
					std :: cout << i << ' ';
				std :: cout << '\n';
				return ;
			}
		std :: cout << "NO\n";
		return ;
	}

	if(pos[c[m]].size() == 0 && plan[c[m]].size() == 0) {
		std :: cout << "NO\n";
		return ;
	}

	for(int i = m; i >= 1; -- i) {
		// deb(i);
		if(pos[c[i]].size() == 0) {
			if(plan[c[i]].size() > 0) ans[i] = *plan[c[i]].begin();
			else ans[i] = ans[i+1];
			continue;
		}
		plan[c[i]].push_back(*pos[c[i]].rbegin());
		ans[i] = *pos[c[i]].rbegin(); pos[c[i]].pop_back();
	}
	for(int i = 1; i <= n; ++ i)
		if(pos[b[i]].size() > 0) {
			std :: cout << "NO\n";
			return ;
		}
	std :: cout << "YES\n";
	for(int i = 1; i <= m; ++ i)
		std :: cout << ans[i] << ' ';
	std :: cout << '\n';
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
