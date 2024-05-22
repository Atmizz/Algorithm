#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1010;
void solve() {
	int n; std :: cin >> n;
	std :: vector <int> a(n<<1);
	for(int i = 0; i < n << 1; ++ i)
		std :: cin >> a[i];
	std :: sort(a.begin(), a.end());
	for(int i = 0; i < (n << 1) - 1; ++ i) {
		std :: map <int, int> cnt;
		for(int j = 0; j < (n << 1); ++ j)
			cnt[a[j]] ++;
		int x = a[i] + a[(n<<1)-1];
		std :: vector <pi> ans;

		for(int j = (n << 1) - 1; j >= 0; -- j) {
			if(cnt[a[j]] == 0) continue;
			if(cnt[x-a[j]] == 0) break;
			if(a[j] << 1 == x && cnt[a[j]] == 1) break;
			ans.push_back({x-a[j], a[j]});
			cnt[x-a[j]] --; cnt[a[j]] --; x = a[j];
		}
		// deb(ans.size());
		if(ans.size() == n) {
			std :: cout << "YES\n" << a[i] + a[(n<<1)-1] << endl;
			for(auto [s, t] : ans)
				std :: cout << s << ' ' << t << endl;
			 return ;
		}
	}
	std :: cout << "NO" << endl;
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