#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1010;
int n, k, m;
void solve() {
	std :: cin >> n >> k;
	int deg = 0;
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		if(u == k || v == k) deg ++;
	}
	if(deg <= 1) {
		std :: cout << "Ayush\n";
		return ;
	}
	if((n - 1) % 2)
		std :: cout << "Ayush\n";
	else std :: cout << "Ashish\n";
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