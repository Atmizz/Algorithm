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
const int MaxN = 1e4 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int heap[MaxN], n, heapSize, fa[MaxN], m;
std :: map <int, int> mr;
struct Node {
  int l, r, val;
}t[MaxN];
void insertHeap(int u) {
  int now, next;
  heap[++heapSize] = u;
  now = heapSize;
  while(now > 1) {
    next = now >> 1;
    if(heap[now] >= heap[next]) return ;
    std :: swap(heap[now], heap[next]);
    now = next;
  }
}
void dfs(int k, int pa) {
  t[k].val = heap[k]; fa[k] = pa; mr[t[k].val] = k;
  // std :: cout << t[k].val << ' ' << k << ' ' << pa << '\n';
  if(heap[ls]) t[k].l = ls, dfs(ls, k);
  if(heap[rs]) t[k].r = rs, dfs(rs, k);
}
int main() {
  n = read(); m = read();
  for(int i = 1; i <= n; ++ i) {
    int x = read(); insertHeap(x);
  } dfs(1, 0);
  while(m --) {
    int u = read(), v, flag = 1; std :: string s;
    std :: cin >> s; u = mr[u];
    if(s == "and") {
      v = read(); v = mr[v]; std :: cin >> s >> s;
      if(fa[u] != fa[v]) flag = 0;
      // std :: cout << "and\n";
    } else {
      std :: cin >> s;
      if(s == "a") {
        std :: cin >> s >> s; v = read(); v = mr[v];
        if(fa[u] != v) flag = 0;
        // std :: cout << "a child\n";
      } else {
        std :: cin >> s;
        if(s == "root") {
          if(u != 1) flag = 0;
          // std :: cout << "root\n";
        }
        else {
          std :: cin >> s; v = read(); v = mr[v];
          if(fa[v] != u) flag = 0;
          // std :: cout << "parent\n";
        }
      }
    } //std :: cout << u << ' ' << v << '\n';
    printf(flag ? "T\n" : "F\n");
  }
  return 0;
}