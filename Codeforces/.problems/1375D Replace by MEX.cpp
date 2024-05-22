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
// const int N = ;
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <int> a(n+1), cnt(n+1);
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		cnt[a[i]] ++;
	}
	int ans = 0;
	std :: vector <int> v;
	bool fg = 1;
	while(1) {
		bool flag = 1;
		for(int i = 2; i <= n; ++ i) {
			if(a[i] < a[i-1]) {
				flag = 0;
				break;
			}
		}
		if(flag == 1) {
			
			break;
		}
		int mex = 0;
		for(int i = 0; i <= n; ++ i) {
			if(!cnt[i]) {
				mex = i;
				break;
			}
		}
		if(mex == n) {
			fg = 0;
			break;
		}
		for(int i = 1; i <= n; ++ i) {
			if(cnt[a[i]] > 1 || a[i] == n) {
				cnt[a[i]] --;
				cnt[mex] ++;
				ans ++;
				v.push_back(i);
				a[i] = mex;
				break;
			}
		}
	}
	// deb(ans);
	if(fg == 0) {
		std :: vector <int> vis(n+1);
		std :: vector <int> adj(n+1);
		for(int i = 1; i <= n; ++ i) {
			adj[i] = a[i] + 1;
		}
		for(int i = n; i >= 1; -- i) {
			if(!vis[i] && a[i] != i - 1) {
				std :: queue <int> q;
				q.push(i);
				while(q.size()) {
					int u = q.front();
					if(vis[u]) {
						ans ++;
						v.push_back(i);
						break ;
					}
					// deb(u);
					vis[u] = 1; q.pop();
					ans ++; v.push_back(u);
					q.push(adj[u]);
				}
			}
		}
	}
	std :: cout << ans << '\n';
	for(auto x : v) {
		std :: cout << x << ' ';
	}
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