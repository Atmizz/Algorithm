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
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
void solve() {
	int a, b, k;
	std :: cin >> a >> b >> k;
	int g = gcd(a, b);
	if(k == 1 && a == b) {
		std :: cout << "NO\n";
		return ;
	}
	if(k == 1) {
		if(g == a || g == b)
			std :: cout << "YES\n";
		else std :: cout << "NO\n";
		return ;
	}
	int cnt = 0, res = a;
	for(int i = 2; i * i <= res; ++ i)
		while(a % i == 0) cnt ++, a /= i;
	if(a > 1) cnt ++;
	res = b;
	for(int i = 2; i * i <= res; ++ i)
		while(b % i == 0) cnt ++, b /= i;
	if(b > 1) cnt ++;
	std :: cout << (cnt >= k ? "YES\n" : "NO\n");
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