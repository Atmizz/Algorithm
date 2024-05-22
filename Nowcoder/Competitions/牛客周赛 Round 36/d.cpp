#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline int max(int a, int b) { return a > b ? a : b;}
inline int min(int a, int b) { return a < b ? a : b;}
inline int abs(int a) { return a < 0 ? -a : a;}
const int MaxN = 4e6 + 20;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, dis[MaxN], head[MaxN], cnt;
char g[1100][1100];
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
struct Edge { 
	int to, net, dis;
}e[MaxN<<1];
struct Node {
	int x, dis;
	friend bool operator < (Node a, Node b) {
		return a.dis > b.dis;
	}
};
void Insert(int u, int v, int w) {
	e[++cnt] = {v, head[u], w};
	head[u] = cnt;
}
void Dijstra() {
	memset(dis, 0x3f, sizeof dis); dis[1] = 0;
	std :: priority_queue <Node> q; q.push({1, 0});
	while(q.size()) {
		Node p = q.top(); q.pop();
		int u = p.x, d = p.dis;
		if(d != dis[u]) continue;
		for(int i = head[u]; i; i = e[i].net) {
			int v = e[i].to;
			if(dis[v] > dis[u] + e[i].dis) {
				dis[v] = dis[u] + e[i].dis;
				q.push({v, dis[v]});
			}
		}
	}
}
int main() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> g[i][j];
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			for(int k = 0; k < 4; ++ k) {
				int dx = i + xx[k], dy = j + yy[k];
				if(dx < 1 || dx > n || dy < 1 || dy > m || g[i][j] == g[dx][dy]) {
					continue;
				}
				// std :: cout << i << ' ' << j << '\n';
				// std :: cout << dx << ' ' << dy << ";\n";
				// std :: cout << (i-1)*m+j << ' ' << (dx-1)*m+dy << '\n';
				Insert((i-1)*m+j, (dx-1)*m+dy, 1);
				Insert((dx-1)*m+dy, (i-1)*m+j, 1);
			}
		}
	}
	Dijstra();
	// for(int i = 1; i <= n * m; ++ i) {
	// 	std :: cout << i << ' ' << dis[i] << '\n';
	// }
	std :: cout << (dis[n*m] == 1061109567 ? -1 : dis[n*m]);
	return 0;
}