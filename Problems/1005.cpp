#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <map>
#include <vector>
#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
#define gc getchar()
typedef unsigned long long ll;
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = - 1;
	for(; ch >= '0' && ch <= '9'; ch = gc) s = (s << 3) + (s << 1) + (ch ^ 48);
	return s * f;
}
inline int abs(int a) { return a < 0 ? -a : a;}
inline int max(int a, int b) { return a > b ? a : b;}
inline int min(int a, int b) { return a < b ? a : b;}
const int MaxN = 1e6 + 200;
const int mod = 1e9 + 7;
const int INF = 0x7fffffff;
char ans[55][55];
int main() {
	int T = read();
	for(int GB = 1; GB <= T; ++ GB) {
		int n = read();
		for(int i = 1; i <= n; ++ i)
			for(int j = 1; j <= n; ++ j)
				ans[i][j] = ' ';
		for(int i = 1; i <= n; ++ i) ans[i][1] = ans[1][i] = ans[n][i] = ans[i][n] = '*';
		for(int i = 1; i <= n; ++ i)
			ans[i][i] = ans[i][n-i+1] = ans[n-i+1][i] = ans[n-i+1][n-i+1] = '*';
		for(int i = 1; i <= n; ++ i) {
			for(int j = 1; j <= n; ++ j)
				std :: cout << ans[i][j];
			std :: cout << '\n';
		}
	}
}