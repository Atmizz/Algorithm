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
const int N = 110;
int n, m, h[N], d[N];
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> d[i] >> h[i];
	bool flag = 0;
	for(int i = 1; i <= n; ++ i)
		if(d[i] > h[i] || d[i] >= m) {
			flag = 1; break;
		}
	if(!flag) {
		std :: cout << -1 << '\n';
		return ;
	}
	int maxx = 0, res = 0;
	for(int i = 1; i <= n; ++ i)
		maxx = std :: max(maxx, d[i]);
	if(maxx >= m) {
		std :: cout << "1\n";
		return ;
	}
	for(int i = 1; i <= n; ++ i) 
		res = std :: max(res, d[i] - h[i]);
	std :: cout << (int)ceil((m + res - maxx) * 1.00 / res) << '\n';
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