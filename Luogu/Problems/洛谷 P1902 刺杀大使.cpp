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
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int Map[1005][1005], n, m, cnt, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool vis[1005][1005];
bool Ck(int x, int y) {
	if(x < 1 || x > n || y < 1 || y > m) return false;
	return true;
}
struct Node {
  int x, y;
};
bool BFS(int z) {
	std :: queue <Node> q;
  q.push({1, 1}); vis[1][1] = 1;
  while(!q.empty()) {
    int x = q.front().x, y = q.front().y; q.pop();
    for(int i = 0; i < 4; ++ i) {
      int xx = x + dx[i], yy = y + dy[i];
			if(Ck(xx, yy) && Map[xx][yy] <= z && !vis[xx][yy]) q.push({xx,yy}), vis[xx][yy] = 1;
		}
  }
  for(int i = 1; i <= m; ++ i)
    if(!vis[n][i]) return false;
  return true;
}
bool Check(int x) {
	memset(vis, 0, sizeof vis);
  if(BFS(x)) return true;
	return false;
}
int main() {
 // freopen("P1902_2.in", "r", stdin);
	n = read(), m = read(); 
  int l = 0, r = 1, mid;
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j)
			Map[i][j] = read(), r = std :: max(r, Map[i][j]);
	while(l < r) {
		mid = (l + r) >> 1;
		if(Check(mid)) r = mid;
		else l = mid + 1;
	} printf("%d", l);
	return 0;
}