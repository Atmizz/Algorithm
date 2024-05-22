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
// const int N = ;
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <int> a(n), ans(n);
	for(int &x : a) {
		std :: cin >> x;
	}
	std :: map <int, int> mp;
	// int mex = 0;
	for(int i = 0; i < n; ++ i) {
		int p1 = i - a[i];
		int p2 = i - a[i] + 1;
		std :: cout << p1 << ' ' << p2 << '\n';
		if(!mp.count(p1) && p1 < n && p1 >= 0) {
			ans[i] = p1;
			mp[p1] = 1;
		} else {
			ans[i] = p2;
			mp[p2] = 1;
		}
	}
	for(int x : ans) {
		std :: cout << x << ' ';
	}
	std :: cout << '\n';
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