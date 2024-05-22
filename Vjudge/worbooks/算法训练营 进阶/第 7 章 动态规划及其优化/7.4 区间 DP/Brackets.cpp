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
const int N = 110;
char s[N];
int f[N][N];
bool match(int i, int j) {
	return (s[i] == '[' && s[j] == ']') || (s[i] == '(' && s[j] == ')');
}
void solve() {
	while(1) {
		scanf("%s", s + 1);
		if(s[1] == 'e') return ;
		int n = strlen(s + 1);
		for(int i = 1; i <= n; ++ i)
			for(int j = 1; j <= n; ++ j)
				f[i][j] = 0;
		for(int len = 1; len < n; ++ len)
			for(int i = 1; i + len - 1 <= n; ++ i) {
				int j = i + len;
				if(match(i, j)) f[i][j] = f[i+1][j-1] + 2;
				for(int k = i; k < j; ++ k)
					f[i][j] = std :: max(f[i][j], f[i][k] + f[k+1][j]);
			}
		std :: cout << f[1][n] << endl;
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
