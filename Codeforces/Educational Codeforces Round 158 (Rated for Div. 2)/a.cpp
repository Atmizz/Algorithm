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
const int N = 100;
int n, x, a[N];
bool check(int y) {
	int lst = 0;
	for(int i = 1; i <= n; ++ i) {
		if(a[i] - lst > y) return false;
		lst = a[i];
	}
	if((x - a[n]) * 2 > y) return false;
	lst = x;
	for(int i = n; i >= 1; -- i) {
		if(lst - a[i] > y) return false;
		lst = a[i];
	}
	if(a[1] > y) return false;
	return true;
}
void solve() {
	std :: cin >> n >> x;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	int l = 0, r = 200, ans;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	std :: cout << ans << endl;
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