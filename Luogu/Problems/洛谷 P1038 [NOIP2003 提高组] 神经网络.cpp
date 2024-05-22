#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = gc)
		s = (s << 1) + (s << 3) + (ch ^ 48);
	return s * f;
}
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 120;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, p, U[MaxN], W[MaxN][MaxN], C[MaxN], du[MaxN], chu[MaxN], ans, d[MaxN];
std :: vector <int> edge[MaxN];
int main() {
	n = read(), p = read();
	for(int i = 1; i <= n; ++ i) {
		C[i] = read(), U[i] = read();
		if(C[i] == 0) C[i] -= U[i];
	}
	for(int i = 1; i <= p; ++ i) {
		int u = read(), v = read();
		edge[u].push_back(v);
		W[u][v] = read();
		du[v] ++; chu[u] ++; d[v] ++;
	}
	std :: queue <int> q;
	for(int i = 1; i <= n; ++ i)
		if(!du[i]) q.push(i);
		else if(!chu[i]) chu[0] ++;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if(C[u] <= 0 && d[u] > 0) continue;
		for(int i = 0; i < edge[u].size(); ++ i) {
			int v = edge[u][i]; du[v] --;
			C[v] += W[u][v] * C[u];
			if(du[v] == 0) q.push(v);
		}
	}
	for(int i = 1; i <= n; ++ i)
		if(chu[i] == 0 && C[i] > 0) ans ++;
	if(ans == 0) printf("NULL");
	else 
		for(int i = 1; i <= n; ++ i)
			if(chu[i] == 0 && C[i] > 0) printf("%d %d\n", i, C[i]);
	return 0;
}