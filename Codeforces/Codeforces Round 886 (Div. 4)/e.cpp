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
	i64 n, c;
	std :: cin >> n >> c;
	std :: vector <i64> s(n+1);
	for(int i = 1; i <= n; ++ i)
		std :: cin >> s[i];
	i64 l = 0, r = 1e9;
	while(l <= r) {
		i64 mid = (l + r) >> 1;
		i64 sum = 0;
		for(int i = 1; i <= n; ++ i) {
			sum += (s[i] + 2 * mid) * (s[i] + 2 * mid);
			if(sum > c) break;
		}
		if(sum >= c) r = mid - 1;
		else l = mid + 1;
		// deb(mid);
	} std :: cout << r + 1<< endl;
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}