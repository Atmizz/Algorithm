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
const int N = 12;
int n;
bool ok, vis[N];
struct Node {
	int t, d, l;
}a[N];
void dfs(int num, int last) {
	if(ok) {
		return ;
	}
	if(num == n) {
		ok = true;
		return ;
	}
	for(int i = 1; i <= n; ++ i) {
		if(vis[i]) {
			continue ;
		}
		if(last > a[i].t + a[i].d) {
			return ;
		}
		vis[i] = 1;
		dfs(num + 1, std :: max(last, a[i].t) + a[i].l);
		vis[i] = 0;
	}
}
void solve() {
	std :: cin >> n;
	ok = false;
	for(int i = 1; i <= n; ++ i) {
		vis[i] = false;
		std :: cin >> a[i].t >> a[i].d >> a[i].l;
	}
	for(int i = 1; i <= n; ++ i) {
		vis[i] = 1;
		dfs(1, a[i].t+a[i].l);
		vis[i] = 0;
	}
	std :: cout << (ok ? "YES\n" : "NO\n");
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