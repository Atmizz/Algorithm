#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;

const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;

void Oula(int a) {
	int res = a; // res *= (1-1/p)
		for(int i = 2; i <= a / i; ++ i)
			if(a % i == 0) {
				res = res / i * (i - 1);
				while(a % i == 0) a /= i;
			}
		if(a > 1) res = res / a * (a - 1);
		std :: cout << res << endl;
}

void solve() {
	int n;
	std :: cin >> n;
	while(n --) {
		int a;
		std :: cin >> a;
		Oula(a);
	}
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T;
	while(T --) solve();
	return 0;
}