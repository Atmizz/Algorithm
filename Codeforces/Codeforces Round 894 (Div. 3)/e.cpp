#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

void solve() {
	i64 n, m, d, ans = 0, res = 0;
	std :: cin >> n >> m >> d;
	std :: vector <i64> a(n);
	for(i64 i = 0; i < n; ++ i)
		std :: cin >> a[i];
	std :: priority_queue <i64, std :: vector <i64>, std :: greater <i64> > q;
	for(int i = 0; i < n; ++ i) {
		if(a[i] < 0) continue;
		if(q.size() < m) q.push(a[i]), res += a[i];
		else
			if(a[i] > q.top()) {
				res += a[i], res -= q.top();
				q.pop(); q.push(a[i]);
			}
		ans = std :: max(ans, res - d * (i + 1));
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