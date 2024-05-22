#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;

int exgcd(int a, int b, int &x, int &y) {
	if(!b) {
		x = 1, y = 0;
		return a;
	}
	int d = exgcd(b, a % b, x, y);
	int temp = x;
	x = y; y = temp - (a / b) * y;
	return d;
}

void solve() {
	int a, b, x, y, m; // ax - my = b
	std :: cin >> a >> b >> m;
	int gcd = exgcd(a, m, x, y);
	if(b % gcd) {
		std :: cout << "impossible\n";
		return ;
	}
	std :: cout << (i64)x * (b / gcd) % m << endl;
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}