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
	int n, cnt = 0;
	std :: cin >> n;
	std :: vector <int> a(n), ans;
	for(int i = 0; i < n; ++ i) std :: cin >> a[i];
	for(int i = 0; i < n; ++ i)
		if(i == 0 || a[i] >= a[i-1]) ans.push_back(a[i]);
		else {
			ans.push_back(a[i]);
			ans.push_back(a[i]);
		}
	std :: cout << ans.size() << endl;
	for(auto x : ans)
		std :: cout << x << ' ';
	std :: cout << endl;
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