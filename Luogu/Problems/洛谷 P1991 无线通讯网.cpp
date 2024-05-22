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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int S, P, cnt, pa[MaxN], k;
double x[MaxN], y[MaxN], ans;
struct Node {
  int x, y;
  double z;
  friend bool operator < (Node a, Node b) {
    return a.z < b.z;
  }
}e[MaxN];
int Find(int x) {
  return x == pa[x] ? pa[x] : pa[x] = Find(pa[x]);
}
int main() {
  S = read(); P = read();
  for(int i = 1; i <= P; ++ i)
    scanf("%lf %lf", &x[i], &y[i]), pa[i] = i;
  for(int i = 1; i <= P; ++ i)
    for(int j = 1; j < i; ++ j)
      e[++cnt] = {i, j, sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]))};
std :: sort(e + 1, e + 1 + cnt);
for(int i = 1; i <= cnt; ++ i) {
  int u = Find(e[i].x), v = Find(e[i].y);
  if(u == v) continue; pa[u] = v;
  ans = e[i].z; k ++;
  if(k >= P - S) {
    printf("%.2lf", ans);
    return 0;
  }
}
  return 0;
}