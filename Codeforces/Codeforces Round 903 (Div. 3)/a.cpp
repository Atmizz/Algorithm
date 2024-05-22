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
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 110;
void solve() {
	int n, m;
	std :: cin >> n >> m;
	std :: string a, b;
	std :: cin >> a >> b;
	for(int opt = 0; ; ++ opt) {
		bool flag = 1;
		if(opt > 100) {
			std :: cout << -1 << endl;
			return ;
		}
		if(a.find(b) != -1) {
			std :: cout << opt << endl;
			return ;
		}
		a = a + a;
	}
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
