#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
#define int unsigned long long
typedef long long ll;
inline int read() {
  int s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
    s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int t, n, k, c, cnt, head[MaxN], ans, l[MaxN][2];
struct Edge {
  int to, net;
}e[MaxN];
void Insert(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
}
void dfs(int x, int fa) {
	for(int i = head[x]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == fa) continue; dfs(v,x);
		if(l[v][0] + 1 > l[x][0])
			l[x][1] = l[x][0], l[x][0] = l[v][0] + 1;
		else if(l[v][0] + 1 > l[x][1])
			l[x][1] = l[v][0] + 1;
	}
}
signed main() { 
  t = read();
  while(t --) {
    n = read(); k = read(); c = read();
    ans = 0;  cnt = 0;
    for(int i = 1; i <= n; ++ i)
      head[i] = l[i][0] = l[i][1] = 0;
    for(int i = 1; i < n; ++ i) {
      int u = read(), v = read();
      Insert(u, v); Insert(v, u);
    } dfs(1, 0);
    printf("%lld\n", max(k * (l[1][0] + l[1][1]) - c * l[1][1], l[1][0] * k));
  }
  return 0;
}