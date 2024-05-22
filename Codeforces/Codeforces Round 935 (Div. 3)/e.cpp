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
int n, x, p[N], pos[N];
void solve() {
	std :: cin >> n >> x;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> p[i];
		pos[p[i]] = i;
	}
	int l = 1, r = n + 1;
	while(1) {
		if(r - l == 1) {
			break;
		}
		int mid = (l + r) >> 1;
		if(p[mid] <= x) {
			l = mid;
		} else {
			r = mid;
		}
	}
	if(p[l] == x) {
		std :: cout << 0 << '\n';
		return ;
	}
	std :: cout << 1 << '\n';
	std :: cout << l << ' ' << pos[x] << '\n';
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