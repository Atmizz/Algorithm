#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <cmath>
#include <bitset>
#include <complex>
#include <cstdlib>
#include <set>
#include <cstring>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
typedef long long i64;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 10010;
int f[N], w[N], v[N], n, m, E, F;
void solve() {
	std :: cin >> E >> F; m = F - E;
	for(int i = 1; i <= m; ++ i) f[i] = -INF;
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> v[i] >> w[i], v[i] = - v[i];
	for(int i = 1; i <= n; ++ i)
		for(int j = w[i]; j <= m; ++ j)
			f[j] = std :: max(f[j], f[j-w[i]] + v[i]);
	if(f[m] == -INF) std :: cout << "This is impossible.\n";
	else std :: cout << "The minimum amount of money in the piggy-bank is " << -f[m] << "." << endl;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	scanf("%d", &T); 
	while(T --) solve();
	return 0;
}