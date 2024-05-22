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
int N, a[15][15], b[15][15], ans[15][15], x, y, z;
int main() {
	N = read();
	for(int OO = 1; OO <= N; ++ OO) {
/*
		for(int i = 1; i <= 15; ++ i)
			for(int j = 1; j <= 15; ++ j)
				a[i][j] = b[i][j] = ans[i][j] = 0;
*/
		x = read(), y = read(), z = read();
		for(int i = 1; i <= x; ++ i)
			for(int j = 1;j <= y; ++ j)
				a[i][j] = read();
		for(int i = 1; i <= y; ++ i)
			for(int j = 1; j <= z; ++ j)
				b[i][j] = read();
		for(int i = 1; i <= x; ++ i)
			for(int j = 1; j <= z; ++ j) {
				ans[i][j] = 0;
				for(int k = 1; k <= y; ++ k)
					ans[i][j] += (a[i][k] * b[k][j]);
			}
		for(int i = 1; i <= x; ++ i) {
			for(int j = 1; j <= z; ++ j)
				std :: cout << ans[i][j] << ' ';
			std :: cout << '\n';
		}
	}
}