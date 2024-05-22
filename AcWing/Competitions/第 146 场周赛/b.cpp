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
	const int N = 110;
	int n, b, a[N];
	void solve() {
		std :: cin >> n >> b;
		for(int i = 1; i <= n; ++ i) {
			std :: cin >> a[i];
		}
		std :: vector <int> v;
		int cnt1 = 0, cnt2 = 0;
		for(int i = 1; i < n; ++ i) {
			if(a[i] & 1) cnt1 ++;
			else cnt2 ++;	
			if(cnt1 == cnt2) {
				v.push_back(std :: abs(a[i] - a[i+1]));
			}
		}
		std :: sort(v.begin(), v.end());
		int ans = 0;
		for(auto x : v) {
			// deb(x);
			if(ans + x > b) {
				break;
			}
			ans ++;
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