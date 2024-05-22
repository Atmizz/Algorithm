#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;

void solve() {
	int n, num;
	i64 ans = 0;
	std :: cin >> n;
	std :: vector <int> a(n), b(n);
	for(int i = 0; i < n; ++ i) std :: cin >> a[i];
	for(int i = 0; i < n; ++ i) std :: cin >> b[i], num += (b[i] == 1);
	std :: sort(a.begin(), a.end());
	for(int i = n - 1; i >= n - num; -- i)
		ans += a[i];
	std :: cout << ans;
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}