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
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
void solve() {
	int n, L, R; std :: cin >> n >> L >> R;
	std :: vector <int> a(n);
	for(int i = 0; i < n; ++ i)
		std :: cin >> a[i];
	for(int i = 0; i < n; ++ i) {
		if(a[i] < L) std :: cout << L << ' ';
		else if(a[i] >= L && a[i] <= R) std :: cout << a[i] << ' ';
		else std :: cout << R << ' ';
	}
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