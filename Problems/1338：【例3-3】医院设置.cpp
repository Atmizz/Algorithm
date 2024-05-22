#include <bits/stdc++.h>
#define gc getchar()
#define ll long long
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = gc)
		s = (s << 1) + (s << 3) + (ch ^ 48);
	return s * f;
}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
inline int abs(int a) {return a < 0 ? -a : a;}
const int INF = 0x7fffffff;
const int MaxN = 2e5 + 200;
const int Mod = 1e9 + 7;
int Map[205][205], People[205], ans = INF, n;
int main() {
	memset(Map, 0x3f, sizeof Map);
	n = read();
	for(int i = 1; i <= n; ++ i) {
		Map[i][i] = 0; People[i] = read();
		int x = read(), y = read();
		if(x) Map[x][i] = Map[i][x] = 1;
		if(y) Map[y][i] = Map[i][y] = 1;
	}
	for(int k = 1; k <= n; ++ k)
		for(int i = 1; i <= n; ++ i)
			if(i != k)
				for(int j = 1; j <= n; ++ j)
					if(j != i && j != k && Map[i][j] > Map[i][k] + Map[k][j])
						Map[i][j] = Map[j][i] = Map[i][k] + Map[k][j];
	for(int i = 1; i <= n; ++ i) {
		int Now = 0;
		for(int j = 1; j <= n; ++ j)
			Now += People[j] * Map[i][j];
		ans = min(ans, Now);
	}
	printf("%d", ans);
	return 0;
}