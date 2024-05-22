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

std :: string made(int x) {
	std :: string s = "";
	while(x) s = char(((x % 2) & 1) + 48) + s, x /= 2;
	return s;
}

void solve() {
	int N = 1000;
	std :: cout << N * N << endl;
	for(int i = 1; i <= N; ++ i) {
		std :: string str = made(i);
		for(int j = 1; j <= N; ++ j)
			std :: cout << str << ' ' << j << '\n';
	}
}

int main() {
	//freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
//	std :: ios :: sync_with_stdio(false);
//	std :: cin.tie(0);
//	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}
