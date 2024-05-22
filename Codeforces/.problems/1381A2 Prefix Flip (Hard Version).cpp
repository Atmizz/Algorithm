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
	int n;
	std :: cin >> n;
	std :: string s, t;
	std :: cin >> s >> t;
	std :: vector <int> a, b;
	for(int i = 1; i < n; ++ i)
		if(s[i] != s[i-1]) a.push_back(i);
	for(int i = 1; i < n; ++ i)
		if(t[i] != t[i-1]) b.push_back(i);
	if(s[n-1] != t[n-1]) a.push_back(n);
	std :: cout << a.size() + b.size() << ' ';
	for(auto x : a)
		std :: cout << x << ' ';
	for(int i = b.size() - 1; i >= 0; -- i)
		std :: cout << b[i] << ' ';
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