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
const int MaxN = 1e4 + 20;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int pa[MaxN], n, m, cnt;
std :: unordered_set <int> s;
int Find(int x) {
  return x == pa[x] ? pa[x] : pa[x] = Find(pa[x]);
}
int main() {
  n = read();
  for(int i = 1; i < MaxN; ++ i) pa[i] = i;
  for(int i = 1; i <= n; ++ i) {
    int k = read(), u, v;
    if(k > 0) {
      u = read(); s.insert(u);
      u = Find(u);
      for(int j = 1; j < k; ++ j) {
        v = read(); s.insert(v);
        v = Find(v); pa[v] = u;
      }
    }
  }
  for(auto x : s)
    if(pa[x] == x) cnt ++;
  printf("%d %d\n", s.size(), cnt);
  m = read();
  while(m --) {
    int u = read(), v = read();
    u = Find(u); v = Find(v);
    printf(u == v ? "Y\n" : "N\n");
  }
  return 0;
}