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
int T;
ll dp[15][15];
int main() {
	T = read(); dp[0][1] = 1; dp[1][0] = 1;// dp[0][0] = 1;
/*	for(int i = 0; i <= 10; ++ i) {
		for(int j = 0; j <= 10; ++ j)
			std :: cout << dp[i][j] << ' ';
		std :: cout << '\n';
	} std :: cout << '\n';
*/
	for(int i = 0; i <= 10; ++ i)
		for(int j = 0; j <= 10; ++ j) {
			if((i == 1 && j == 0) || (i == 0 && j == 1)) continue;
			else if(i != 0 && j != 0) dp[i][j] = dp[i-1][j] + dp[i][j-1];
			else if(i == 0 && j != 0) dp[i][j] = dp[i][j-1];
			else dp[i][j] = dp[i-1][j];
//			std :: cout << "dp" << i << ' ' << j << " :" << dp[i][j] << '\n';
//			std :: cout << dp[i-1][j] << ' ' << dp[i][j-1] << '\n';
		}
/*	for(int i = 0; i <= 10; ++ i) {
		for(int j = 0; j <= 10; ++ j)
			std :: cout << dp[i][j] << ' ';
		std :: cout << '\n';
	}
*/
	for(int i = 1; i <= T; ++ i) {
		int x = read(), y = read();
		std :: cout << dp[x][y] << '\n';
	}
	
}