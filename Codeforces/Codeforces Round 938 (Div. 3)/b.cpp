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
	int n, c, d;
	std :: cin >> n >> c >> d;
	std :: vector <int> a(n*n+1);
	std :: vector b(n+2, std :: vector <int> (n+2));
	std :: map <int, int> mp;
	int minn = INF;
	for(int i = 1; i <= n * n; ++ i) {
		std :: cin >> a[i];
		mp[a[i]] ++;
		minn = std :: min(minn, a[i]);
	}
	b[1][1] = minn;
	for(int i = 1; i < n; ++ i) {
		for(int j = 1; j < n; ++ j) {
			b[i+1][j] = b[i][j] + c;
			b[i][j+1] = b[i][j] + d;
		}
	}
	b[n][n] = b[n][n-1] + d;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			mp[b[i][j]] --;
			if(mp[b[i][j]] < 0) {
				std :: cout << "NO\n";
				return ;
			}
		}
	}
	std :: cout << "YES\n";
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