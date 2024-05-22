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
const int MaxN = 1e5+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, head[MaxN<<1], cnt, num, Indu[MaxN];
std :: vector <int> ans;
std :: queue <int> q;
struct Edge {
  int to, net;
}e[MaxN << 1];
void Insert(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
}
bool Topsort() {
  for(int i = 1; i <= n; ++ i)
    if(!Indu[i]) q.push(i), ans.push_back(i);
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to; Indu[v] --;
      if(!Indu[v]) q.push(v), ans.push_back(v);
    }
  } return ans.size() == n;
}
int main() {
  n = read(); m = read();
  for(int i = 1; i <= m; ++ i) {
    int u = read(), v = read();
    Insert(u, v); Indu[v] ++;
  }
  if(Topsort())
    for(int i = 0; i < ans.size(); ++ i)
      printf("%d ", ans[i]);
  else printf("-1");
  return 0;
}