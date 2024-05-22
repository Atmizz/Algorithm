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
// const int N = ;
void solve() {
	int n, m;
	std :: cin >> n >> m;
	std :: map <int, int> g, f;
	std :: vector <int> a[m + 1], ans(m + 1);
	for(int i = 1; i <= m; ++ i) {
		int k; std :: cin >> k;
		for(int j = 1; j <= k; ++ j) {
			int x; std :: cin >> x; a[i].push_back(x);
			g[x] ++;
		}
	}
	int pos = 0;
	for(auto [x, y] : g)
		if(y >= ceil((double)m / 2)) pos = x;
	std :: priority_queue <PII> q;
	for(int i = 1; i <= m; ++ i)
		q.push({-a[i].size(), i});
	int cnt = 0;
	while(q.size()) {
		int flag = 0;
		if(cnt < ceil((double)m / 2))
			for(auto x : a[q.top().second])
				if(x == pos) {
					flag = 1;
					ans[q.top().second] = x; cnt ++; break;
				}
		if(flag == 0) {
			for(auto x : a[q.top().second])
				if(x != pos && f[x] <= ceil((double)m / 2)) {
					ans[q.top().second] = x;break;
				}
		}
		q.pop();
	}

	for(int i = 1; i <= m; ++ i)
		if(ans[i] == 0) {
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