#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;

i64 ten[20];

void solve() {
	i64 x;
	std :: cin >> x;
	for(int i = 0; i <= 18; ++ i) {
		i64 X = (x + 1) * ten[i];
		i64 y = std :: sqrt(X);
		if(y * y > 1e18) {
			std :: cout << -1 << endl;
			return ;
		}
		if(y * y / ten[i] == x) {
			std :: cout << y << endl;
			return ;
		}
	}
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	ten[0] = 1;
	for(int i = 1; i <= 18; ++ i) ten[i] = ten[i-1] * 10ll;
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}