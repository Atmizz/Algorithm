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
const int N = 550;
int f[N][N];
char s1[N], s2[N];
void solve() {
	while(~scanf("%s %s", s1 + 1, s2 + 1)) {
		int l1 = strlen(s1 + 1), l2 = strlen(s2 + 1);
		for(int i = 1; i <= l1; ++ i) f[i][0] = 0;
		for(int i = 1; i <= l2; ++ i) f[0][i] = 0;
		for(int i = 1; i <= l1; ++ i) 
			for(int j = 1; j <= l2; ++ j) {
				if(s1[i] == s2[j]) f[i][j] = f[i-1][j-1] + 1;
				else f[i][j] = std :: max(f[i-1][j], f[i][j-1]);
			}
		std :: cout << f[l1][l2] << endl;
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	//scanf("%d", &T); 
	while(T --) solve();
	return 0;
}