#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
	if(!b) {
		x = 1, y = 0;
		return a;
	}
	i64 d = exgcd(b, a % b, x, y);
	i64 temp = x;
	x = y; y = temp - (a / b) * y;
	return d;
}

void solve() {
	i64 n, d, x, y, a, b;
	std :: cin >> n >> d >> a >> b;
	i64 c = b - a;
	i64 gcd = exgcd(d, n, x, y);
	// a + x * d = b (mod n)
	// a + dx + ny = b
	if(c % gcd != 0) std :: cout << "Impossible\n";
	else {
		i64 ans = x * c / gcd;
		while(ans < 0) ans += n / gcd;
		std :: cout << (ans + n / gcd) % (n / gcd) << endl;
	}
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