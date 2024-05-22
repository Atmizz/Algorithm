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
const int MaxN = 5e3 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, K, pa[MaxN], cnt, u[MaxN], v[MaxN], sum;
bool vis[MaxN];
int Find(int x) {
  return x == pa[x] ? x : pa[x] = Find(pa[x]);
}
int main() {
  n = read(); m = read();
  for(int i = 0; i < n; ++ i) pa[i] = i;
  for(int i = 1; i <= m; ++ i) {
    u[i] = read(), v[i] = read();
    int U = Find(u[i]), V = Find(v[i]);
    pa[U] = V;
  } K = read(); sum = n;
  for(int i = 0; i < n; ++ i) pa[i] = Find(pa[i]);
  while(K --) {
    int k = read(); vis[k] = 1; int last = -1; sum --;
     std :: unordered_set <int> s;
    for(int i = 0; i < n; ++ i)
      if(pa[i] == pa[k] && i != k) s.insert(i), last = i;
    if(last == -1) {
      printf("City %d is lost.\n", k);
      if(sum == 0) {
        printf("Game Over.");
        continue;
      }
      continue;
    }
    for(int i = 0; i < n; ++ i) pa[i] = i;
    for(int i = 1; i <= m; ++ i) {
      if(vis[u[i]] || vis[v[i]]) continue;
      int U = Find(u[i]), V = Find(v[i]);
      pa[U] = V;
    }
    for(int i = 0; i < n; ++ i) pa[i] = Find(pa[i]);
    for(int i = 0; i < n; ++ i)
      if(pa[last] == pa[i]) s.erase(i);
    if(s.empty()) printf("City %d is lost.\n", k);
    else printf("Red Alert: City %d is lost!\n", k);
  }
  return 0;
}