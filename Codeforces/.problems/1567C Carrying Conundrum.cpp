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
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 20;
void solve() {
	std :: string s; std :: cin >> s;
	int n = s.length();
	int a = 0, b = 0;
	for(int i = 0; i < n; ++ i)
		if(i % 2 == 0) a = a * 10 + (s[i] - '0');
		else b = b * 10 + (s[i] - '0');
	std :: cout << (a + 1) * (b + 1) - 2 << endl;
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