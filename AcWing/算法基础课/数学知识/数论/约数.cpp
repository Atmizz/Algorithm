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

void get_divisors(int n) {
	std :: vector <int> res;
	for(int i = 2; i <= n / i; ++ i)
		if(n % i == 0) {
			res.push_back(i);
			if(i * i != n) res.push_back(n / i);
		}
	std :: sort(res.begin(), res.end());
	for(auto x : res)
		std :: cout << x << ' ';
}

void solve() {
	int n;
	std :: cin >> n;
	get_divisors(n);
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