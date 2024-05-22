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
const i64 Range = 1e18;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
int n;
i64 k, sumx[N], sumy[N];
struct Pointx {
	i64 x, y;
	friend bool operator <(Pointx a, Pointx b) {
		return a.x < b.x;
	}
}x[N];
struct Pointy {
	i64 x, y;
	friend bool operator <(Pointy a, Pointy b) {
		return a.y < b.y;
	}
}y[N];
bool check(i64 z) {
	i64 res = 0, a = 1e18, b = 1e18;
	for(i64 i = 1; i <= n; ++ i) {
		i64 pos = std :: upper_bound(x + 1, x + n + 1, 
			(Pointx){x[i].x + z, Range}) - x - 1;z
		// deb(pos);
		a = std :: min(a, 
			(i - 1) * x[i].x - sumx[i-1] + sumx[n] - sumx[pos] - (n - pos) * (x[i].x + z));
	}

	for(int i = 1; i <= n; ++ i) {
		i64 pos = std :: upper_bound(y + 1, y + n + 1, 
			(Pointy){Range, y[i].y + z}) - y - 1;
		b = std :: min(b, 
			(i - 1) * y[i].y - sumy[i-1] + sumy[n] - sumy[pos] - (n - pos) * (y[i].y + z));
	}
	res = a + b;
	// deb(res);
	return (res <= k);
}

void solve() {
	std :: cin >> n >> k;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> x[i].x >> x[i].y, y[i].x = x[i].x, y[i].y = x[i].y;

	std :: sort(x + 1, x + 1 + n);
	std :: sort(y + 1, y + 1 + n);
	x[n+1].x = y[n+1].y = Range;

	for(int i = 1; i <= n; ++ i)
		sumx[i] = sumx[i-1] + x[i].x;
	for(int i = 1; i <= n; ++ i)
		sumy[i] = sumy[i-1] + y[i].y;

	i64 l = 0, r = 1e18, ans = 0, mid;
	while(l <= r) {
		mid = (l + r) / 2;
		if(check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	std :: cout << ans;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}
