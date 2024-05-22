#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;

void solve() {
	std :: string s1, s2;
	std :: cin >> s1 >> s2;
	if(s1 == "0" && s2 != "0") {
		std :: cout << "-1";
		return ;
	}
	int n = s1.length(), m = s2.length();
	i64 ans = 0, f = 1, x = 0, y = 0;
	for(int i = n - 1; i >= 0; -- i) x += f * (s1[i] - '0'), f *= 2;
	f = 1;
	for(int i = m - 1; i >= 0; -- i) y += f * (s2[i] - '0'), f *= 2;
	std :: cout << std :: abs(x - y);

}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	// std :: cin >> T; 
	while(T --) solve();
	return 0;
}