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
std :: vector <PII> line(N);
int n;
bool check(int l) {
	int L = 0, R = 0;
	// deb(l);
	for(int i = 1; i <= n; ++ i) {
		int x = line[i].first;
		int y = line[i].second;
		L = L - l;
		R = R + l;
		// std :: cout << L << ' ' << R << '\n';
		if(R < x || L > y) return false;
		L = std :: max(L, x);
		R = std :: min(R, y);
	}
	return true;
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> line[i].first >> line[i].second;
	int l = 0, r = Range, ans;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
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