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

void solve() {
	int a, b, q;
	std :: cin >> a >> b >> q;
	std :: vector <i64> sum(a*b + 1);
	for(int i = 0; i < a * b; ++ i)
		if(i % a % b != i % b % a) sum[i] = 1;
	for(int i = 1; i < a * b; ++ i)
		sum[i] += sum[i-1];
	auto query = [&] (i64 x) -> i64 {
		i64 t = a * b;
		return x / t * sum[t-1] + sum[x % t];
	};
	while(q --) {
		i64 l, r;
		std :: cin >> l >> r;
		std :: cout << query(r) - query(l - 1) << ' ';
	}
	std :: cout << endl;
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