#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#define Max 4000015
#define re register
#define INF 0x7fffffff
inline int read() {
  int s = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = s * 10 + ch - 48, ch = getchar();
  return s * f;
}
int m, n, dis[Max], head[Max], cnt, sum[Max >> 1];
bool vis[Max >> 1] = {0};
const int mod = 100003;
struct edge {
  int net, to;
} t[Max];
void add(int u, int v) {
  t[++cnt].net = head[u];
  t[cnt].to = v;
  head[u] = cnt;
}
std::queue<int> q;
void SPFA() {
  for (re int i = 2; i <= n; ++i)
    dis[i] = INF, sum[i] = 0;
  vis[1] = 1; q.push(1);
  dis[1] = 0; sum[1] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (re int i = head[u]; i; i = t[i].net) {
      int v = t[i].to;
      if (dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        sum[v] = sum[u];
        if (!vis[v])
          q.push(v), vis[v] = 1;
      }
      else if (dis[v] == dis[u] + 1)
        sum[v] += sum[u], sum[v] %= mod;
    }
  }
}
int main() {
  n = read(); m = read();
  int u, v;
  for (re int i = 1; i <= m; ++i) {
    u = read(); v = read();
    add(u, v); add(v, u);
  } SPFA();
  for (re int i = 1; i <= n; ++i)
    printf("%d\n", sum[i] % mod);
  return 0;
}