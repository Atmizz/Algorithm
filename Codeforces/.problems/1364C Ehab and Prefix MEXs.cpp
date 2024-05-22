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
	int n;
	std :: cin >> n;
	std :: vector <int> a(n), ans(n, -1);
	for(int i = 0; i < n; ++ i)
		std :: cin >> a[i];
	for(int i = 1; i < n; ++ i)
		if(a[i] < a[i-1] || a[i] > i + 1) {
			std :: cout << -1;
			return ;
		}
	int now = 0, cn = 0;
	for(int i = 0; i < n; ++ i) {
		for(int j = cn; j < a[i]; ++ j)
			if(ans[i] == -1) ans[i] = j;
			else {
				while(ans[now] != -1) now ++;
				ans[now] = j;
			}
			cn = a[i];
	}
	for(auto x : ans)
		std :: cout << (x == -1 ? 113232 : x) << ' ';
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