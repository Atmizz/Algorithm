#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

bool check(int x) {
	return x & 1;
}

void solve() {
	int n;
	std :: cin >> n;
	std :: vector <int> a(n), b(n);
	for(int i = 0; i < n; ++ i)
		std :: cin >> a[i], b[i] = a[i];
	std :: sort(b.begin(), b.end());
	for(int i = 0; i < n; ++ i)
		if(check(a[i]) != check(b[i])) {
			std :: cout << "NO\n";
			return ;
		}
	std :: cout << "YES\n";
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