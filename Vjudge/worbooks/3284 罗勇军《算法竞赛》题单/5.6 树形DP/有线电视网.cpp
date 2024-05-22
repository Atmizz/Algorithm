/*
f[i][j] 表示到i节点，花费了j，
*/
#include <bits/stdc++.h>
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
const int MaxN = 3030;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, head[MaxN], cnt, val[MaxN];
struct Edge {
  int to, net, was;
}e[MaxN];
void Insert(int u, int v, int w) {
  e[++cnt] = (Edge) {v, head[u], w};
}
int main() {
  n = read(); m = read();
  for(int i = 1; i <= n - m; ++ i) {
    int k = read();
    for(int j = 1; j <= k; ++ j) {
      int u = read(), w = read();
      Insert(i, u, w);
    }
  }
  for(int i = n - m + 1; i <= n; ++ i) val[i] = read();
  
  return 0;
}