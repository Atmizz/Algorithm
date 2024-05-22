#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
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
	int n, m; std :: cin >> n >> m;
	std :: vector <std :: string> a(n);
	for(int i = 0; i < n; ++ i)
		std :: cin >> a[i];
	for(int j = 0; j < m; ++ j) {
		std :: string ans = a[0];
		for(int k = 0; k < 26; ++ k) {
			ans[j] = char(k + 'a');
			int flag = 0;
			for(int h = 0; h < n; ++ h) {
				int cnt = 0;
				for(int s = 0; s < m; ++ s)
					if(ans[s] != a[h][s]) cnt ++;
				if(cnt > 1) {
					flag = 1;
					break;
				}
				if(flag == 1) break;
			}
			if(flag == 0) {
				std :: cout << ans << endl;
				return ;
			}
		}
	}
	std :: cout << -1 << endl;
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