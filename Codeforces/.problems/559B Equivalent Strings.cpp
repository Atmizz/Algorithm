#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
std :: string dfs(std :: string a) {
	if(a.length() & 1) {
		return a;
	}
	int n = a.length() / 2;
	std :: string s1 = dfs(std :: string(a, 0, n));
	std :: string s2 = dfs(std :: string(a, n, n));
	return (s1 < s2) ? s1 + s2 : s2 + s1;
}
void solve() {
	std :: string s1, s2;
	std :: cin >> s1 >> s2;
	std :: cout << (dfs(s1) == dfs(s2) ? "YES" : "NO");
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