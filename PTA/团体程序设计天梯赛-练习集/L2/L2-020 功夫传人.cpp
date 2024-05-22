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
const int MaxN = 1e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n;
double attack[MaxN], r, ans;
int bigger[MaxN];
std :: vector <int> son[MaxN];
void dfs(int u, int fa) {
  if(u != 0) attack[u] = attack[fa] * (1 - r);
  if(bigger[u] > 0.00)
    ans += attack[u] * bigger[u];
  for(auto v : son[u]) dfs(v, u);
}
int main() {
  n = read(); scanf("%lf %lf", &attack[0], &r); r /= 100;
  for(int i = 0; i < n; ++ i) {
    int x = read();
    if(x == 0) {
      if(i != 0) attack[i] = -1;
      scanf("%d", &bigger[i]);
      continue;
    }
    while(x --) {
      int a = read(); son[i].push_back(a);
    }
  } dfs(0, 0);
  if(n == 1) ans = attack[0] * bigger[0];
  printf("%d", int(ans));
  return 0;
}