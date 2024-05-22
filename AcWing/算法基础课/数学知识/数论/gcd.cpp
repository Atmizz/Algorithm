#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;

const int N = 0;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

void solve() {
	int a, b;
	std :: cin >> a >> b;
	std :: cout << gcd(a, b);
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