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
	if(b == 0) {
		x = 1; y = 0;
		return a;
	}
	int d = exgcd(b, a % b, x, y);
	int temp = x;
	x = y; y = temp - (a / b) * y;
	return d;
}

void solve() {
	int a, b, x, y;
	std :: cin >> a >> b;
	int gcd = exgcd(a, b, x, y);
	std :: cout << x << ' ' << y << endl;
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