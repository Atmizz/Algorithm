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
const int N = 1010;
int n, a[N], f[N], len;
void solve() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i)
		scanf("%d", &a[i]);
	f[++len] = a[1];
	for(int i = 2; i <= n; ++ i)
		if(a[i] > f[len]) f[++len] = a[i];
		else if(a[i] < f[len])
			* std :: upper_bound(f + 1, f + 1 + len, a[i]) = a[i];
	std :: cout << len;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	//scanf("%d", &T); 
	while(T --) solve();
	return 0;
}