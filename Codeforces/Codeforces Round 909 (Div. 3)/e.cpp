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
// const int N = ;
void solve() {
	int n; std :: cin >> n;
	std :: vector <int> a(n);
	for(int i = 0; i < n; ++ i)
		std :: cin >> a[i];
	int minn = INF, pos = 0;
	for(int i = 0; i < n; ++ i)
		if(minn > a[i]) pos = i, minn = a[i];
	for(int i = pos + 1; i < n; ++ i)
		if(a[i] < a[i-1]) {
			std :: cout << -1 << '\n';
			return ;
		}
	std :: cout << pos << '\n';
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