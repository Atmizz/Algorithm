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
const int N = 2020;
int r, g, b, R[N], G[N], B[N];
i64 dp[220][220][220];
i64 dfs(int a, int b, int c) {
	if(dp[a][b][c]) return dp[a][b][c];
	if(a && b) dp[a][b][c] = std :: max(dp[a][b][c],
		dfs(a-1, b-1, c) + R[a] * G[b]);
	if(a && c) dp[a][b][c] = std :: max(dp[a][b][c],
		dfs(a-1, b, c-1) + R[a] * B[c]);
	if(b && c) dp[a][b][c] = std :: max(dp[a][b][c],
		dfs(a, b-1, c-1) + G[b] * B[c]);
	return dp[a][b][c];
}
void solve() {
	std :: cin >> r >> g >> b;
	for(int i = 1; i <= r; ++ i)
		std :: cin >> R[i];
	for(int i = 1; i <= g; ++ i)
		std :: cin >> G[i];
	for(int i = 1; i <= b; ++ i)
		std :: cin >> B[i];
	std :: sort(R + 1, R + 1 + r);
	std :: sort(G + 1, G + 1 + g);
	std :: sort(B + 1, B + 1 + b);
	std :: cout << dfs(r, g, b);
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