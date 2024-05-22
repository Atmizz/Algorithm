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
const int N = 60;
int n, a[N], s, r;
void solve() {
	std :: cin >> n >> s >> r;
	a[n] = s - r;
	for(int i = 1; i < n; ++ i)
		a[i] = 0;
	int i = 1;
	while(r) {
		a[i] ++;
		r --;
		i ++;
		i = i % n;
		if(i == 0) i = 1;
	}
	for(int i = 1; i <= n; ++ i)
		std :: cout << a[i] << ' ';
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