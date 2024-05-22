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
const int N = 5e5 + 20;
int a[N], n, x;
void solve() {
	std :: cin >> n >> x;
	for(int i = 1; i <= n; ++ i) {
		int x; std :: cin >> x;
		a[x] ++;
	}
	for(int i = 1; i < x; ++ i) {
		while(a[i] % (i + 1) == 0 && a[i] > 0) a[i+1] ++, a[i] -= (i + 1);
		if(a[i] > 0) {
			std :: cout << "No\n";
			return ;
		}
	}
	std :: cout << "Yes\n";
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