#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
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
const int N = 2020;
int w[26], n, m, f[N][N];
char s[N];
void solve() {
	scanf("%d %d", &n, &m);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; ++ i) {
		char x; int a, b;
		std :: cin >> x;
		scanf("%d %d", &a, &b);
		w[x-'a'] = std :: min(a, b);
	}
	for(int j = 1; j <= m; ++ j)
		for(int i = j - 1; i >= 1; -- i)
			if(s[i] == s[j]) f[i][j] = f[i+1][j-1];
			else f[i][j] = std :: min(f[i+1][j] + w[s[i]-'a'], f[i][j-1] + w[s[j]-'a']);
	std :: cout << f[1][m];
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	//scanf("%d", &T); 
	while(T --) solve();
	return 0;
}