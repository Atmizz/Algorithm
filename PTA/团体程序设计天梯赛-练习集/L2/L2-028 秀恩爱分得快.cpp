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
const int MaxN = 1020;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, sex[MaxN], a[MaxN];
double g[MaxN][MaxN];
struct Node {
  double val;
  int id;
  friend bool operator < (Node a, Node b) {
    return a.val == b.val ? a.id < b.id : a.val > b.val;
  }
};
std :: vector <Node> b, c;
int main() {
  n = read(); m = read();
  for(int i = 1; i <= m; ++ i) {
    int k = read();
    for(int j = 1; j <= k; ++ j) {
      a[j] = read();
      sex[abs(a[j])] = a[j] / abs(a[j]);
    }
    for(int j = 1; j <= k; ++ j)
      for(int l = j+1; l <= k; ++ l)
        if(a[j] * a[l] < 0)
          g[abs(a[j])][abs(a[l])] += 1 / k, g[abs(a[l])][abs(a[j])] += 1 / k;
  }
  std :: cout << "ok\n";
  int x = read(), y = read();
  for(int i = 0; i < n; ++ i)
    if(abs(x) != i && g[abs(x)][i])
      b.push_back({g[abs(x)][i], i});
  for(int i = 0; i < n; ++ i)
    if(abs(y) != i && g[abs(y)][i])
      c.push_back({g[abs(y)][i], i});
  std :: sort(b.begin(), b.end());
  std :: sort(c.begin(), c.end());
  if(g[abs(x)][abs(y)] == b[0].val && g[abs(y)][abs(x)] == c[0].val) {
    printf("%d %d", x, y);
    return 0;
  }
  printf("%d", x);
  for(auto f : b)
    if(f.val == b[0].val) printf(" %d", f.id * sex[f.id]);
  puts("");
  printf("%d", y);
  for(auto f : c)
    if(f.val == c[0].val) printf(" %d", f.id * sex[f.id]);
  return 0;
}