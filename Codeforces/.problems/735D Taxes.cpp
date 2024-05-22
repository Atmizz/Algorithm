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
const int N = 0;
int n, ans;
bool isPrime(int x) {
	for(int i = 2; i <= sqrt(x); ++ i)
		if(x % i == 0) return false;
	return true;
}
void solve() {
	std :: cin >> n;
	if(n == 2 || n == 3 || n == 5 || n == 7 || isPrime(n)) ans = 1;
	else if(n & 1) {
		if(isPrime(n-2)) ans = 2;
		else ans = 3;
	}
	else ans = 2;
	std :: cout << ans;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}