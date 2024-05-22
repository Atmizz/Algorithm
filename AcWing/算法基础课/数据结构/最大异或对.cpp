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
const int N = 1e5 + 200;

int n, idx, son[N*31][2], a[N];

void Insert(int x) {
	int p = 0;
	for(int i = 30; i >= 0; -- i) {
		int t = x >> i & 1;
		if(!son[p][t]) son[p][t] = ++ idx;
		p = son[p][t];
	}
}

int query(int x) {
	int p = 0, res = 0;
	for(int i = 30; i >= 0; -- i) {
		int t = x >> i & 1;
		if(son[p][!t]) res = (res << 1) + (!t), p = son[p][!t];
		else res = (res << 1) + t, p = son[p][t];
	}
	return res;
}

void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) std :: cin >> a[i], Insert(a[i]);
	int ans = 0;
	for(int i = 1; i <= n; ++ i)
		ans = std :: max(ans, query(a[i]) ^ a[i]);
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