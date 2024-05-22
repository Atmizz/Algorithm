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
	int n, ans = 0;
	std :: cin >> n;
	std :: vector <int> num(n+1), a(n+1);
	for(int i = 0; i < n; ++ i) {
		int x; std :: cin >> x;
		if(x <= n) a[x] ++;
	}
	for(int i = 1; i <= n; ++ i)
		if(a[i] > 0)
			for(int j = i; j <= n; j += i)
				num[j] += a[i];
	for(int i = 1; i <= n; ++ i) ans = std :: max(ans, num[i]);
  std :: cout << ans << endl;
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