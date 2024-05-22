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

bool isPrime(int x) {
	if(x < 2) return false;
	for(int i = 2; i < std :: sqrt(x); ++ i)
		if(x % i == 0) return false;
	return true;
}

void devide(int x) {
	for(int i = 2; i <= x / i; ++ i) {
		int sum = 0;
		while(x % i == 0) x /= i, sum ++;
		if(sum) std :: cout << i << ' ' << sum << endl;
	}
	if(x > 1) std :: cout << x << ' ' << 1;
}

void solve() {
	std :: cout << isPrime(4) << endl;
	devide(100);
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